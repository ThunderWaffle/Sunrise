#pragma once

#include <array>
#include <cstddef>

#include "controller_bindings.h"

namespace sunrise::state::account::settings::controller_bindings {

/** Array position is the fixed native slot for the named semantic controller action. */
inline constexpr std::array<ControllerAction, kControllerActionCount>
    kControllerActionsByNativeSlot{
        ControllerAction::fire,
        ControllerAction::toogleZoom,
        ControllerAction::holdZoom,
        ControllerAction::melee,
        ControllerAction::unused0,
        ControllerAction::grenade,
        ControllerAction::super,
        ControllerAction::reload,
        ControllerAction::altWeaponAction,
        ControllerAction::finisher,
        ControllerAction::lightAttack,
        ControllerAction::heavyAttack,
        ControllerAction::block,
        ControllerAction::swapToPower,
        ControllerAction::swapToKineticOrEnergy,
        ControllerAction::nextWeapon,
        ControllerAction::prevWeapon,
        ControllerAction::switchToKinetic,
        ControllerAction::switchToEnergy,
        ControllerAction::switchToPower,
        ControllerAction::unused1,
        ControllerAction::unused2,
        ControllerAction::unused3,
        ControllerAction::unused4,
        ControllerAction::jump,
        ControllerAction::toggleCrouch,
        ControllerAction::holdCrouch,
        ControllerAction::sprint,
        ControllerAction::holdSprint,
        ControllerAction::boost,
        ControllerAction::brake,
        ControllerAction::zoom,
        ControllerAction::dodgeLeft,
        ControllerAction::altDodgeLeft,
        ControllerAction::dodgeRight,
        ControllerAction::altDodgeRight,
        ControllerAction::vehicleFirePrimary,
        ControllerAction::vehicleFireSecondary,
        ControllerAction::vehicleExit,
        ControllerAction::interact,
        ControllerAction::highlightPlayer,
        ControllerAction::emoteOne,
        ControllerAction::emoteTwo,
        ControllerAction::emoteThree,
        ControllerAction::emoteFour,
        ControllerAction::warlockDive,
        ControllerAction::warlockDash,
        ControllerAction::titanBarrier,
        ControllerAction::hunderDodge,
        ControllerAction::warlockRift,
    };

/** Verifies that every semantic controller action owns exactly one native slot. */
[[nodiscard]] consteval bool complete_controller_slot_map() noexcept {
    std::array<bool, kControllerActionCount> seen{};
    for (const ControllerAction action : kControllerActionsByNativeSlot) {
        const std::size_t stateIndex = static_cast<std::size_t>(action);
        if (stateIndex >= seen.size() || seen[stateIndex]) {
            return false;
        }
        seen[stateIndex] = true;
    }
    return true;
}

static_assert(complete_controller_slot_map());

} // namespace sunrise::state::account::settings::controller_bindings
