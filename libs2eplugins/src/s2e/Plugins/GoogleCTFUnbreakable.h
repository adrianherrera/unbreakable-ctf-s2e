///
/// Copyright (C) 2017, Dependable Systems Laboratory, EPFL
/// All rights reserved.
///
/// Copy this file to source/s2e/libs2eplugins/src/s2e/Plugins in your S2E
/// environment.
///

#ifndef S2E_PLUGINS_GOOGLE_CTF_UNBREAKABLE_H
#define S2E_PLUGINS_GOOGLE_CTF_UNBREAKABLE_H

#include <s2e/CorePlugin.h>
#include <s2e/Plugin.h>
#include <s2e/S2E.h>

namespace s2e {
namespace plugins {

class ProcessExecutionDetector;

class GoogleCTFUnbreakable : public Plugin {
    S2E_PLUGIN

public:
    GoogleCTFUnbreakable(S2E *s2e) : Plugin(s2e) {
    }

    void initialize();

private:
    ProcessExecutionDetector *m_procDetector;

    void onSymbolicVariableCreation(S2EExecutionState *state, const std::string &name,
                                    const std::vector<klee::ref<klee::Expr>> &expr, const klee::MemoryObject *mo,
                                    const klee::Array *array);
    void onTranslateInstruction(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb, uint64_t pc);
    void onSuccess(S2EExecutionState *state, uint64_t pc);
    void onFailure(S2EExecutionState *state, uint64_t pc);
};

} // namespace plugins
} // namespace s2e

#endif
