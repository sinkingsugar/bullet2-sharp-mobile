#include <LinearMath/btPoolAllocator.h>

#include "conversion.h"
#include "btDefaultCollisionConfiguration_wrap.h"

btDefaultCollisionConstructionInfo* btDefaultCollisionConstructionInfo_new()
{
	return new btDefaultCollisionConstructionInfo();
}

btPoolAllocator* btDefaultCollisionConstructionInfo_getCollisionAlgorithmPool(btDefaultCollisionConstructionInfo* obj)
{
	return obj->m_collisionAlgorithmPool;
}

int btDefaultCollisionConstructionInfo_getCustomCollisionAlgorithmMaxElementSize(btDefaultCollisionConstructionInfo* obj)
{
	return obj->m_customCollisionAlgorithmMaxElementSize;
}

int btDefaultCollisionConstructionInfo_getDefaultMaxCollisionAlgorithmPoolSize(btDefaultCollisionConstructionInfo* obj)
{
	return obj->m_defaultMaxCollisionAlgorithmPoolSize;
}

int btDefaultCollisionConstructionInfo_getDefaultMaxPersistentManifoldPoolSize(btDefaultCollisionConstructionInfo* obj)
{
	return obj->m_defaultMaxPersistentManifoldPoolSize;
}

btPoolAllocator* btDefaultCollisionConstructionInfo_getPersistentManifoldPool(btDefaultCollisionConstructionInfo* obj)
{
	return obj->m_persistentManifoldPool;
}

int btDefaultCollisionConstructionInfo_getUseEpaPenetrationAlgorithm(btDefaultCollisionConstructionInfo* obj)
{
	return obj->m_useEpaPenetrationAlgorithm;
}

void btDefaultCollisionConstructionInfo_setCollisionAlgorithmPool(btDefaultCollisionConstructionInfo* obj, btPoolAllocator* value)
{
	obj->m_collisionAlgorithmPool = value;
}

void btDefaultCollisionConstructionInfo_setCustomCollisionAlgorithmMaxElementSize(btDefaultCollisionConstructionInfo* obj, int value)
{
	obj->m_customCollisionAlgorithmMaxElementSize = value;
}

void btDefaultCollisionConstructionInfo_setDefaultMaxCollisionAlgorithmPoolSize(btDefaultCollisionConstructionInfo* obj, int value)
{
	obj->m_defaultMaxCollisionAlgorithmPoolSize = value;
}

void btDefaultCollisionConstructionInfo_setDefaultMaxPersistentManifoldPoolSize(btDefaultCollisionConstructionInfo* obj, int value)
{
	obj->m_defaultMaxPersistentManifoldPoolSize = value;
}

void btDefaultCollisionConstructionInfo_setPersistentManifoldPool(btDefaultCollisionConstructionInfo* obj, btPoolAllocator* value)
{
	obj->m_persistentManifoldPool = value;
}

void btDefaultCollisionConstructionInfo_setUseEpaPenetrationAlgorithm(btDefaultCollisionConstructionInfo* obj, int value)
{
	obj->m_useEpaPenetrationAlgorithm = value;
}

void btDefaultCollisionConstructionInfo_delete(btDefaultCollisionConstructionInfo* obj)
{
	delete obj;
}

btDefaultCollisionConfiguration* btDefaultCollisionConfiguration_new(btDefaultCollisionConstructionInfo* constructionInfo)
{
	return new btDefaultCollisionConfiguration(*constructionInfo);
}

btDefaultCollisionConfiguration* btDefaultCollisionConfiguration_new2()
{
	return new btDefaultCollisionConfiguration();
}

btVoronoiSimplexSolver* btDefaultCollisionConfiguration_getSimplexSolver(btDefaultCollisionConfiguration* obj)
{
	return obj->getSimplexSolver();
}

void btDefaultCollisionConfiguration_setConvexConvexMultipointIterations(btDefaultCollisionConfiguration* obj, int numPerturbationIterations, int minimumPointsPerturbationThreshold)
{
	obj->setConvexConvexMultipointIterations(numPerturbationIterations, minimumPointsPerturbationThreshold);
}

void btDefaultCollisionConfiguration_setConvexConvexMultipointIterations2(btDefaultCollisionConfiguration* obj, int numPerturbationIterations)
{
	obj->setConvexConvexMultipointIterations(numPerturbationIterations);
}

void btDefaultCollisionConfiguration_setConvexConvexMultipointIterations3(btDefaultCollisionConfiguration* obj)
{
	obj->setConvexConvexMultipointIterations();
}

void btDefaultCollisionConfiguration_setPlaneConvexMultipointIterations(btDefaultCollisionConfiguration* obj, int numPerturbationIterations, int minimumPointsPerturbationThreshold)
{
	obj->setPlaneConvexMultipointIterations(numPerturbationIterations, minimumPointsPerturbationThreshold);
}

void btDefaultCollisionConfiguration_setPlaneConvexMultipointIterations2(btDefaultCollisionConfiguration* obj, int numPerturbationIterations)
{
	obj->setPlaneConvexMultipointIterations(numPerturbationIterations);
}

void btDefaultCollisionConfiguration_setPlaneConvexMultipointIterations3(btDefaultCollisionConfiguration* obj)
{
	obj->setPlaneConvexMultipointIterations();
}
