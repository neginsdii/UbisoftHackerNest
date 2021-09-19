#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <unordered_map>

#include "Game/GameBoard.h"

#include "GameEngine/EntitySystem/Scene.h"
#include "Game/MenuScene.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

namespace GameEngine
{
    enum SceneState
    {
        NoScene = -1,
        Menu_Scene = 0,
        GameBoard_Scene,
        End_Scene,
        Num_of_Scenes
    };
    class GameEngineMain
    {
    public:
        ~GameEngineMain();

        static GameEngineMain* GetInstance() { if (!sm_instance) sm_instance = new GameEngineMain(); return sm_instance; }
        //Returns time between update frames in seconds
        static float		   GetTimeDelta() { return GetInstance()->m_lastDT; }
        static float		   GetGameTime() { return sm_gameClock.getElapsedTime().asSeconds(); }

        sf::RenderTarget* GetRenderTarget() const { return m_renderTarget; }
        sf::RenderWindow* GetRenderWindow() const { return m_renderWindow; }
        void Update();
        void SetRenderTarget(sf::RenderTarget* target) { m_renderTarget = target; }

        void AddEntity(Entity* entity);
        void RemoveEntity(Entity* entity);
        void RemoveAllEntities();
        void RefreshEntityTag(Entity* entity);
        void RemoveEntityTagFromMap(Entity* entity, std::string tag);

        std::vector<Entity*> GetEntitiesByTag(std::string tag);

        void OnInitialised();
    //    bool IsGameOver() const { return m_gameBoard && m_gameBoard->IsGameOver(); }

         //transition between scenes
        void ChangeSceneState(SceneState newState);

        float GetWindowWidth() { return WINDOW_WIDTH; }
        float GetWindowHeight() { return WINDOW_HEIGHT; }

    private:
        GameEngineMain();

        void CreateAndSetUpWindow();

        void AddPendingEntities();
        void RemovePendingEntities();
        void UpdateWindowEvents();
        void UpdateEntities();
        void RenderEntities();

        static float WINDOW_HEIGHT;
        static float WINDOW_WIDTH;

        static GameEngineMain* sm_instance;
        static sf::Clock	   sm_deltaTimeClock;
        static sf::Clock	   sm_gameClock;

        std::vector<Entity*> m_entitiesToAdd;
        std::vector<Entity*> m_entities;
        std::vector<Entity*> m_entitiesToRemove;

        std::unordered_map<std::string, std::vector<Entity*>> m_entityTagMap;
        static std::vector<Entity*> s_emptyEntityTagList;

        sf::RenderTarget* m_renderTarget;
        sf::RenderWindow* m_renderWindow; //In future they will be different						

        float	m_lastDT;

        bool m_windowInitialised;

        Scene* m_currentScene;
        SceneState m_currentSceneState;
    };
}
