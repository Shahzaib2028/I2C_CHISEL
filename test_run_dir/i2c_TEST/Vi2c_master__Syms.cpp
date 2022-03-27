// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vi2c_master__Syms.h"
#include "Vi2c_master.h"



// FUNCTIONS
Vi2c_master__Syms::~Vi2c_master__Syms()
{
}

Vi2c_master__Syms::Vi2c_master__Syms(VerilatedContext* contextp, Vi2c_master* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
