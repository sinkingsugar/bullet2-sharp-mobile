using SiliconStudio.Core.Mathematics;
namespace BulletSharp
{
	public interface IActionInterface
	{
        void DebugDraw(IDebugDraw debugDrawer);
		void UpdateAction(CollisionWorld collisionWorld, float deltaTimeStep);
	}
}
