#include "main.h"

extern "C"
{
	EXPORT btDispatcherInfo* btDispatcherInfo_new();
	EXPORT btScalar btDispatcherInfo_getAllowedCcdPenetration(btDispatcherInfo* obj);
	EXPORT btScalar btDispatcherInfo_getConvexConservativeDistanceThreshold(btDispatcherInfo* obj);
	EXPORT btIDebugDraw* btDispatcherInfo_getDebugDraw(btDispatcherInfo* obj);
	EXPORT int btDispatcherInfo_getDispatchFunc(btDispatcherInfo* obj);
	EXPORT bool btDispatcherInfo_getEnableSatConvex(btDispatcherInfo* obj);
	EXPORT bool btDispatcherInfo_getEnableSPU(btDispatcherInfo* obj);
	EXPORT int btDispatcherInfo_getStepCount(btDispatcherInfo* obj);
	EXPORT btScalar btDispatcherInfo_getTimeOfImpact(btDispatcherInfo* obj);
	EXPORT btScalar btDispatcherInfo_getTimeStep(btDispatcherInfo* obj);
	EXPORT bool btDispatcherInfo_getUseContinuous(btDispatcherInfo* obj);
	EXPORT bool btDispatcherInfo_getUseConvexConservativeDistanceUtil(btDispatcherInfo* obj);
	EXPORT bool btDispatcherInfo_getUseEpa(btDispatcherInfo* obj);
	EXPORT void btDispatcherInfo_setAllowedCcdPenetration(btDispatcherInfo* obj, btScalar value);
	EXPORT void btDispatcherInfo_setConvexConservativeDistanceThreshold(btDispatcherInfo* obj, btScalar value);
	EXPORT void btDispatcherInfo_setDebugDraw(btDispatcherInfo* obj, btIDebugDraw* value);
	EXPORT void btDispatcherInfo_setDispatchFunc(btDispatcherInfo* obj, int value);
	EXPORT void btDispatcherInfo_setEnableSatConvex(btDispatcherInfo* obj, bool value);
	EXPORT void btDispatcherInfo_setEnableSPU(btDispatcherInfo* obj, bool value);
	EXPORT void btDispatcherInfo_setStepCount(btDispatcherInfo* obj, int value);
	EXPORT void btDispatcherInfo_setTimeOfImpact(btDispatcherInfo* obj, btScalar value);
	EXPORT void btDispatcherInfo_setTimeStep(btDispatcherInfo* obj, btScalar value);
	EXPORT void btDispatcherInfo_setUseContinuous(btDispatcherInfo* obj, bool value);
	EXPORT void btDispatcherInfo_setUseConvexConservativeDistanceUtil(btDispatcherInfo* obj, bool value);
	EXPORT void btDispatcherInfo_setUseEpa(btDispatcherInfo* obj, bool value);
	EXPORT void btDispatcherInfo_delete(btDispatcherInfo* obj);

	EXPORT void* btDispatcher_allocateCollisionAlgorithm(btDispatcher* obj, int size);
	EXPORT void btDispatcher_clearManifold(btDispatcher* obj, btPersistentManifold* manifold);
	EXPORT void btDispatcher_dispatchAllCollisionPairs(btDispatcher* obj, btOverlappingPairCache* pairCache, btDispatcherInfo* dispatchInfo, btDispatcher* dispatcher);
	EXPORT btCollisionAlgorithm* btDispatcher_findAlgorithm(btDispatcher* obj, btCollisionObjectWrapper* body0Wrap, btCollisionObjectWrapper* body1Wrap, btPersistentManifold* sharedManifold);
	EXPORT btCollisionAlgorithm* btDispatcher_findAlgorithm2(btDispatcher* obj, btCollisionObjectWrapper* body0Wrap, btCollisionObjectWrapper* body1Wrap);
	EXPORT void btDispatcher_freeCollisionAlgorithm(btDispatcher* obj, void* ptr);
	//EXPORT * btDispatcher_getInternalManifoldPointer(btDispatcher* obj);
	EXPORT btPoolAllocator* btDispatcher_getInternalManifoldPool(btDispatcher* obj);
	EXPORT btPersistentManifold* btDispatcher_getManifoldByIndexInternal(btDispatcher* obj, int index);
	EXPORT btPersistentManifold* btDispatcher_getNewManifold(btDispatcher* obj, btCollisionObject* b0, btCollisionObject* b1);
	EXPORT int btDispatcher_getNumManifolds(btDispatcher* obj);
	EXPORT bool btDispatcher_needsCollision(btDispatcher* obj, btCollisionObject* body0, btCollisionObject* body1);
	EXPORT bool btDispatcher_needsResponse(btDispatcher* obj, btCollisionObject* body0, btCollisionObject* body1);
	EXPORT void btDispatcher_releaseManifold(btDispatcher* obj, btPersistentManifold* manifold);
	EXPORT void btDispatcher_delete(btDispatcher* obj);
}
