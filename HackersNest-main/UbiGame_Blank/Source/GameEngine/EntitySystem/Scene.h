#pragma once
namespace GameEngine
{
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Clean() = 0;
	};
}