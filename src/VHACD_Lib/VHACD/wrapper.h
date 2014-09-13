#ifdef _MSC_VER
#define EXPORT __declspec(dllexport)
#else
#if __GNUC__ >= 4
	#define EXPORT __attribute__ ((visibility("default")))
#else
	#define EXPORT
#endif
#endif

extern "C"
{
	EXPORT void* GenerateCompoundShape(unsigned int vertexCount, unsigned int indicesCount, float* vertexes, unsigned int* indices, unsigned int depth, float cpercent, float ppercent, unsigned int maxVerts, float skinWidth);
	EXPORT void DeleteHulls(void* hulls);
	EXPORT unsigned int GetNumHulls(void* hulls);
	EXPORT unsigned int GetHullNumPoints(void* hulls, unsigned int index);
	EXPORT void CopyHullPoints(void* hulls, unsigned int index, float* outPoints);
}