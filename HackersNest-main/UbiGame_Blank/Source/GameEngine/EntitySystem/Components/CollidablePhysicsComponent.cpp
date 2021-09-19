#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
{

}


CollidablePhysicsComponent::~CollidablePhysicsComponent()
{

}


void CollidablePhysicsComponent::OnAddToWorld()
{
	CollidableComponent::OnAddToWorld();
}


void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	CollidableComponent::OnRemoveFromWorld();
}


void CollidablePhysicsComponent::Update()
{
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();
	bool collision = false;

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;
		if ((this->GetEntity()->GetEntityTag() == "FirstPlayer" && colComponent->GetEntity()->GetEntityTag() == "Trap"))
			continue;

		
		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			if (this->GetEntity()->GetEntityTag() == "Rat" && colComponent->GetEntity()->GetEntityTag() == "Trap")
			{
				this->GetEntity()->SetIsActive(false);
				colComponent->GetEntity()->SetIsActive(false);
				continue;

			}
			if ((colComponent->GetEntity()->GetEntityTag() == "Rat" && this->GetEntity()->GetEntityTag() == "FirstPlayer")
			||(colComponent->GetEntity()->GetEntityTag() == "FirstPlayer" && this->GetEntity()->GetEntityTag() == "Rat")) 
			{
				this->GetEntity()->SetIsActive(false);
				colComponent->GetEntity()->SetIsActive(false);
				continue;
			}
			if (this->GetEntity()->GetEntityTag() == "SecondPlayer" && colComponent->GetEntity()->GetEntityTag() == "Sewage")
			{
				this->GetEntity()->SetIsActive(false);
				continue;

			}
			collision = true;
			if (colComponent->GetEntity()->GetEntityTag() == "Platform")
				this->isColliding = true;
			sf::Vector2f pos = GetEntity()->GetPos();
			/*if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}*/
			/*else
			{*/
			if (myBox.top < colideBox.top)
				pos.y -= intersection.height;
			else
				pos.y += intersection.height;
			//	}

			GetEntity()->SetPos(pos);
		}
	}
	if (!collision)
		this->isColliding = false;
}