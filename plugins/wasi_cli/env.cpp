// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2024 Second State INC

#include "env.h"
#include "module.h"

namespace WasmEdge {
namespace Host {

namespace {

Runtime::Instance::ComponentInstance *createEnvironment(
    const Plugin::PluginComponent::ComponentDescriptor *) noexcept {
  return new WasiCliEnvironmentModule();
}

Runtime::Instance::ComponentInstance *
createExit(const Plugin::PluginComponent::ComponentDescriptor *) noexcept {
  return new WasiCliExitModule();
}

Plugin::Plugin::PluginDescriptor Descriptor{
    .Name = "wasi_cli",
    .Description = "",
    .APIVersion = Plugin::Plugin::CurrentAPIVersion,
    .Version = {0, 1, 0, 0},
    .ModuleCount = 0,
    .ModuleDescriptions = {},
    .ComponentCount = 2,
    .ComponentDescriptions =
        (Plugin::PluginComponent::ComponentDescriptor[]){
            {
                .Name = "wasi:cli/environment@0.2.0",
                .Description = "",
                .Create = createEnvironment,
            },
            {
                .Name = "wasi:cli/exit@0.2.0",
                .Description = "",
                .Create = createExit,
            },
        },
    .AddOptions = nullptr,
};

EXPORT_GET_DESCRIPTOR(Descriptor)

} // namespace
} // namespace Host
} // namespace WasmEdge
