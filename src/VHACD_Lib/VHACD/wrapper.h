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
	EXPORT void* CreateMesh(unsigned int vertexCount, unsigned int indicesCount, float* vertexes, unsigned int* indices);
	EXPORT void DeleteMesh(void* mesh);
	EXPORT void* GenerateCompoundShape(void* mesh, int depth, int posSampling, int angleSampling, int posRefine, int angleRefine, double alpha, double concavityThreshold);
}