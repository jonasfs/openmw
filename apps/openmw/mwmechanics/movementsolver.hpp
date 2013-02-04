#ifndef  GAME_MWMECHANICS_MOVEMENTSOLVER_H
#define  GAME_MWMECHANICS_MOVEMENTSOLVER_H

#include "libs/openengine/bullet/trace.h"
#include "libs/openengine/bullet/physic.hpp"

#include "../mwworld/ptr.hpp"

#include <cmath>

namespace MWMechanics
{
    class MovementSolver
    {
        public:
            MovementSolver(const MWWorld::Ptr &ptr);
            virtual ~MovementSolver();

            Ogre::Vector3 move(const Ogre::Vector3 &position, const Ogre::Vector3 &movement, float time, const Ogre::Vector3 &halfExtents);

        private:
            bool stepMove(Ogre::Vector3& position, const Ogre::Vector3 &velocity, float remainingTime, float verticalRotation, const Ogre::Vector3 &halfExtents, bool isInterior);

            void clipVelocity(const Ogre::Vector3& in, const Ogre::Vector3& normal, Ogre::Vector3& out, const float overbounce);
            void projectVelocity(Ogre::Vector3& velocity, const Ogre::Vector3& direction);

            float getSlope(const Ogre::Vector3 &normal);

            MWWorld::Ptr mPtr;
            OEngine::Physic::PhysicEngine *mEngine;
            OEngine::Physic::PhysicActor *mPhysicActor;

            float verticalVelocity;
    };
}

#endif /* GAME_MWMECHANICS_MOVEMENTSOLVER_H */
