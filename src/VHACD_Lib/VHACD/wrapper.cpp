#include "wrapper.h"
#include "vhacdHACD.h"
#include "BulletCollision/CollisionShapes/btCompoundShape.h"
#include "BulletCollision/CollisionShapes/btConvexHullShape.h"

void CallBack(const char * msg)
{
	return;
}

void* CreateMesh(unsigned int vertexCount, unsigned int indicesCount, float* vertexes, unsigned int* indices)
{
	VHACD::Mesh* mesh = new VHACD::Mesh();

	mesh->ResizePoints(vertexCount);
	mesh->ResizeTriangles(indicesCount);

	for(unsigned int i = 0; i < vertexCount; i++)
	{
		VHACD::Vec3<VHACD::Real> vertex(vertexes[(i * 3) + 0], vertexes[(i * 3) + 1], vertexes[(i * 3) + 2]);
		mesh->SetPoint(i, vertex);
	}

	for(unsigned int i = 0; i < indicesCount; i++)
	{
		VHACD::Vec3<long> index(indices[(i * 3) + 0], indices[(i * 3) + 1], indices[(i * 3) + 2]);
		mesh->SetTriangle(i, index);
	}

	return mesh;
}

void DeleteMesh(void* mesh)
{
	VHACD::Mesh* m = (VHACD::Mesh*)mesh;
	delete m;
}

void* GenerateCompoundShape(void* mesh, int depth, int posSampling, int angleSampling, int posRefine, int angleRefine, double alpha, double concavityThreshold)
{
	VHACD::Mesh* m = (VHACD::Mesh*)mesh;
	std::vector<VHACD::Mesh*> parts;
	if(!VHACD::ApproximateConvexDecomposition(*m, depth, posSampling, angleSampling, posRefine, angleRefine, alpha, concavityThreshold, parts, &CallBack))
	{
		return NULL;
	}

	btCompoundShape* cs = new btCompoundShape();

	for(int i = 0; i < parts.size(); i++)
	{
		VHACD::Mesh convexHull;
		parts[i]->ComputeConvexHull(convexHull);

		std::vector<btScalar> points;
		int npoints = (int)convexHull.GetNPoints();
		for(int p = 0; p < npoints; i++)
		{
			VHACD::Vec3<VHACD::Real> point = convexHull.GetPoint(i);
			points[(i * 3) + 0] = (btScalar)point.X();
			points[(i * 3) + 1] = (btScalar)point.Y();
			points[(i * 3) + 2] = (btScalar)point.Z();
		}

		btConvexHullShape* chs = new btConvexHullShape(&points[0], npoints);

		btTransform identity;
		identity.setIdentity();
		cs->addChildShape(identity, chs);
	}

	return cs;
}
