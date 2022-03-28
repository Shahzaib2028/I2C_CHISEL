// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VI2C_TOP__SYMS_H_
#define _VI2C_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VI2C_Top.h"

// SYMS CLASS
class VI2C_Top__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VI2C_Top*                      TOPp;
    
    // CREATORS
    VI2C_Top__Syms(VI2C_Top* topp, const char* namep);
    ~VI2C_Top__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
