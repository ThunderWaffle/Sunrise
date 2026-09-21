#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

namespace sunrise::state::account::settings::controller_bindings {

/** 
 * Native controller input halves are 16-bit values encoding 2 controller inputs and a flags modifier
 * Bits 0-5 (LSB) are the primary input index, bits 6-11 are the secondary input index, and bits 12-13 are modifier flags.
 * Bits 14-15 are currently unused/reserved.
 */
inline constexpr std::uint16_t kControllerPrimaryMask = 0x003F;
inline constexpr std::uint16_t kControllerSecondaryMask = 0x0FC0;
inline constexpr std::uint16_t kControllerModifierMask = 0xF000;

inline constexpr std::uint8_t kControllerSecondaryShift = 6;
inline constexpr std::uint8_t kControllerModifierShift = 12;

/** The highest allowed value for a controller input is 0x1D which denotes the unbound button. */
inline constexpr std::uint16_t kControllerUnboundInputCode = 0x1d;

/** Modifier flags are mutually exclusive, or all bits are 0  */
inline constexpr std::uint16_t kControllerLongPressModifierFlag = 0x1;
inline constexpr std::uint16_t kControllerDoublePressModifierFlag = 0x2;

/** Authored controller actions whose bindings can be replicated with account settings. */
enum class ControllerAction : std::uint8_t {
    fire,
    toogleZoom,
    holdZoom,
    melee,
    unused0,
    grenade,
    super,
    reload,
    altWeaponAction,
    finisher,
    lightAttack,
    heavyAttack,
    block,
    swapToPower,
    swapToKineticOrEnergy,
    nextWeapon,
    prevWeapon,
    switchToKinetic,
    switchToEnergy,
    switchToPower,
    unused1,
    unused2,
    unused3,
    unused4,
    jump,
    toggleCrouch,
    holdCrouch,
    sprint,
    holdSprint,
    boost,
    brake,
    zoom,
    dodgeLeft,
    altDodgeLeft,
    dodgeRight,
    altDodgeRight,
    vehicleFirePrimary,
    vehicleFireSecondary,
    vehicleExit,
    interact,
    highlightPlayer,
    emoteOne,
    emoteTwo,
    emoteThree,
    emoteFour,
    warlockDive,
    warlockDash,
    titanBarrier,
    hunderDodge,
    warlockRift,
    count,
};

/** The controller binding table has exactly one row per supported action. */
inline constexpr std::size_t kControllerActionCount = static_cast<std::size_t>(ControllerAction::count);

/** Authored controller codes. */
struct Binding {
    std::optional<std::uint8_t> primary;
    std::optional<std::uint8_t> secondary;
    std::optional<std::uint8_t> flags;

    bool operator==(const Binding&) const = default;
};

/** Fixed authored controller binding table independent of the native representation. */
struct ControllerBindings {
    std::array<Binding, kControllerActionCount> values;
    /** True after every supported action has been loaded. */
    bool configured{};

    bool operator==(const ControllerBindings&) const = default;
};

} // namespace sunrise::state::account::settings::controller_bindings
