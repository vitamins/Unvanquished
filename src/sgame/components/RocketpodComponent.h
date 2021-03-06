#ifndef ROCKETPOD_COMPONENT_H_
#define ROCKETPOD_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class RocketpodComponent: public RocketpodComponentBase {
	public:
		// ///////////////////// //
		// Autogenerated Members //
		// ///////////////////// //

		/**
		 * @brief Default constructor of the RocketpodComponent.
		 * @param entity The entity that owns the component instance.
		 * @param r_HumanBuildableComponent A HumanBuildableComponent instance that this component depends on.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		RocketpodComponent(Entity& entity, HumanBuildableComponent& r_HumanBuildableComponent);

		// ///////////////////// //

	private:

};

#endif // ROCKETPOD_COMPONENT_H_
