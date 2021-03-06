#include "main.h"

extern "C"
{
	EXPORT btCompoundCollisionAlgorithm_CreateFunc* btCompoundCollisionAlgorithm_CreateFunc_new();

	EXPORT btCompoundCollisionAlgorithm_SwappedCreateFunc* btCompoundCollisionAlgorithm_SwappedCreateFunc_new();
	EXPORT btCompoundCollisionAlgorithm* btCompoundCollisionAlgorithm_new(btCollisionAlgorithmConstructionInfo* ci, btCollisionObjectWrapper* body0Wrap, btCollisionObjectWrapper* body1Wrap, bool isSwapped);
	EXPORT btCollisionAlgorithm* btCompoundCollisionAlgorithm_getChildAlgorithm(btCompoundCollisionAlgorithm* obj, int n);
}
