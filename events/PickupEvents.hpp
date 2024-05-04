#include <sdk.hpp>

#include "Singleton.hpp"
#include "Gomponent.hpp"
#include "Gamemode.hpp"

class PickupEvents : public PickupEventHandler, public Singleton<PickupEvents>
{
public:
	PickupEvents()
	{
		gamemode_ = Gomponent::Get()->getGamemode();
	}

	void onPlayerPickUpPickup(IPlayer& player, IPickup& pickup) override
	{
		if (pickup.getLegacyPlayer() == nullptr)
		{
			gamemode_->call<unsigned char>("onPlayerPickUpPickup", static_cast<void*>(&player), static_cast<void*>(&pickup));
		}
		else if (auto data = queryExtension<IPlayerPickupData>(player))
		{
			gamemode_->call<unsigned char>("onPlayerPickUpPlayerPickup", static_cast<void*>(&player), static_cast<void*>(&pickup));
		}
	}

private:
	Gamemode* gamemode_;
};
