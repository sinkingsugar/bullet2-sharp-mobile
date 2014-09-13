#include "ConvexBuilder.h"
#include <vector>
#include "wrapper.h"

struct Hull
{
	unsigned int points;
	float* verts;
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
		hull.points = result.mHullVcount*3;
		hull.verts = (float*)malloc(sizeof(float) * hull.points);
		memcpy(hull.verts, result.mHullVertices, sizeof(float) * hull.points);

		Hulls.push_back(hull);
	}
};

void* GenerateCompoundShape(unsigned int vertexCount, unsigned int indicesCount, float* vertexes, unsigned int* indices, unsigned int depth, float cpercent, float ppercent, unsigned maxVerts, float skinWidth)
{
	MyConvexDecomposition cb;

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

	CompoundHull* compound = new CompoundHull();
	compound->count = cb.Hulls.size();
	compound->hulls = (Hull*)malloc(sizeof(Hull) * compound->count);

	for(unsigned int i = 0; i < compound->count; i++)
	{
		compound->hulls[i].points = cb.Hulls[i].points;
		compound->hulls[i].verts = cb.Hulls[i].verts;
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

void DeleteHulls(void* hulls)
{
	CompoundHull* compound = (CompoundHull*)hulls;
	for(unsigned int i = 0; i < compound->count; i++)
	{
		free(compound->hulls[i].verts);
	}

	free(compound->hulls);

	delete compound;
}
