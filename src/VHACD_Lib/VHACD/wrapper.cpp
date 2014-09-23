#include "ConvexBuilder.h"
#include "hacdHACD.h"
#include <vector>
#include "wrapper.h"

struct Hull
{
	unsigned int points;
	float* verts;
	unsigned int indices;
	unsigned int* tris;
};

struct CompoundHull
{
	unsigned int count;
	Hull* hulls;
};

class MyConvexDecomposition : public ConvexDecomposition::ConvexDecompInterface
{	
public:
	std::vector<Hull> Hulls;

	virtual void ConvexDecompResult(ConvexDecomposition::ConvexResult &result)
	{
		Hull hull;

		hull.points = result.mHullVcount * 3;
		hull.verts = (float*)malloc(sizeof(float) * hull.points);
		memcpy(hull.verts, result.mHullVertices, sizeof(float) * hull.points);

		hull.indices = result.mHullTcount * 3;
		hull.tris = (unsigned int*)malloc(sizeof(unsigned int) * hull.indices);
		memcpy(hull.tris, result.mHullIndices, sizeof(unsigned int) * hull.indices);

		Hulls.push_back(hull);
	}
};

void* GenerateCompoundShape(unsigned int vertexCount, unsigned int indicesCount, float* vertexes, unsigned int* indices, unsigned int depth, float cpercent, float ppercent, unsigned maxVerts, float skinWidth)
{
	MyConvexDecomposition cb;

	/*
	ConvexDecomposition::DecompDesc desc;
	
	desc.mCallback = &cb;
	desc.mCpercent = cpercent;
	desc.mDepth = depth;
	desc.mIndices = indices;
	desc.mMaxVertices = maxVerts;
	desc.mPpercent = ppercent;
	desc.mSkinWidth = skinWidth;
	desc.mTcount = indicesCount / 3;
	desc.mVcount = vertexCount;
	desc.mVertices = vertexes;

	ConvexBuilder builder(desc.mCallback);
	unsigned int hullsSize = builder.process(desc);
	*/

	std::vector< HACD::Vec3<HACD::Real> > points;
	std::vector< HACD::Vec3<long> > triangles;

	for(int i=0; i < vertexCount; i++ ) 
	{
		int index = i * 3;
		HACD::Vec3<HACD::Real> vertex(vertexes[index], vertexes[index+1], vertexes[index+2]);
		points.push_back(vertex);
	}

	for(int i=0; i < indicesCount / 3;i++)
	{
		int index = i * 3;
		HACD::Vec3<long> triangle(indices[index], indices[index+1], indices[index+2]);
		triangles.push_back(triangle);
	}

	HACD::HACD myHACD;
	myHACD.SetPoints(&points[0]);
	myHACD.SetNPoints(points.size());
	myHACD.SetTriangles(&triangles[0]);
	myHACD.SetNTriangles(triangles.size());
	myHACD.SetCompacityWeight(0.1);
	myHACD.SetVolumeWeight(0.0);

	// HACD parameters
	// Recommended parameters: 2 100 0 0 0 0
	size_t nClusters = 2;
	double concavity = 10;
	bool invert = false;
	bool addExtraDistPoints = false;
	bool addNeighboursDistPoints = false;
	bool addFacesPoints = false;       

	myHACD.SetNClusters(nClusters);                     // minimum number of clusters
	myHACD.SetNVerticesPerCH(maxVerts);                      // max of 100 vertices per convex-hull
	myHACD.SetConcavity(concavity);                     // maximum concavity
	myHACD.SetAddExtraDistPoints(addExtraDistPoints);   
	myHACD.SetAddNeighboursDistPoints(addNeighboursDistPoints);   
	myHACD.SetAddFacesPoints(addFacesPoints); 

	myHACD.Compute();
	nClusters = myHACD.GetNClusters();

	for (int c=0;c<nClusters;c++)
	{
		//generate convex result
		size_t nPoints = myHACD.GetNPointsCH(c);
		size_t nTriangles = myHACD.GetNTrianglesCH(c);

		float* vertices = new float[nPoints*3];
		unsigned int* triangles = new unsigned int[nTriangles*3];
				
		HACD::Vec3<HACD::Real> * pointsCH = new HACD::Vec3<HACD::Real>[nPoints];
		HACD::Vec3<long> * trianglesCH = new HACD::Vec3<long>[nTriangles];
		myHACD.GetCH(c, pointsCH, trianglesCH);

		// points
		for(size_t v = 0; v < nPoints; v++)
		{
			vertices[3*v] = pointsCH[v].X();
			vertices[3*v+1] = pointsCH[v].Y();
			vertices[3*v+2] = pointsCH[v].Z();
		}
		// triangles
		for(size_t f = 0; f < nTriangles; f++)
		{
			triangles[3*f] = trianglesCH[f].X();
			triangles[3*f+1] = trianglesCH[f].Y();
			triangles[3*f+2] = trianglesCH[f].Z();
		}

		delete [] pointsCH;
		delete [] trianglesCH;

		ConvexResult r(nPoints, vertices, nTriangles, triangles);
		cb.ConvexDecompResult(r);
	}

	//OUTPUT

	CompoundHull* compound = new CompoundHull();
	compound->count = cb.Hulls.size();
	compound->hulls = (Hull*)malloc(sizeof(Hull) * compound->count);

	for(unsigned int i = 0; i < compound->count; i++)
	{
		compound->hulls[i].points = cb.Hulls[i].points;
		compound->hulls[i].verts = cb.Hulls[i].verts;
		compound->hulls[i].indices = cb.Hulls[i].indices;
		compound->hulls[i].tris = cb.Hulls[i].tris;
	}

	return compound;
}

unsigned int GetNumHulls(void* hulls)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	return compound->count;
}

unsigned int GetHullNumPoints(void* hulls, unsigned int index)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	return compound->hulls[index].points;
}

void CopyHullPoints(void* hulls, unsigned int index, float* outPoints)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	memcpy(outPoints, compound->hulls[index].verts, sizeof(float) * compound->hulls[index].points);
}

unsigned int GetHullNumIndices(void* hulls, unsigned int index)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	return compound->hulls[index].indices;
}

void CopyHullIndices(void* hulls, unsigned int index, unsigned int* outIndices)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	memcpy(outIndices, compound->hulls[index].tris, sizeof(unsigned int) * compound->hulls[index].indices);
}

void DeleteHulls(void* hulls)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	for(unsigned int i = 0; i < compound->count; i++)
	{
		free(compound->hulls[i].verts);
		free(compound->hulls[i].tris);
	}

	free(compound->hulls);

	delete compound;
}
