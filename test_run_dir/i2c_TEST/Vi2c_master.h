// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VI2C_MASTER_H_
#define VERILATED_VI2C_MASTER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vi2c_master__Syms;
class Vi2c_master_VerilatedVcd;


//----------

VL_MODULE(Vi2c_master) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_start,0,0);
    VL_IN8(io_addr,6,0);
    VL_IN8(io_data,7,0);
    VL_IN8(io_read_write,0,0);
    VL_IN8(io_i2c_sda_in,0,0);
    VL_OUT8(io_i2c_sda,0,0);
    VL_OUT8(io_i2c_scl,0,0);
    VL_OUT8(io_ready,0,0);
    VL_OUT8(io_stop,0,0);
    VL_OUT8(io_i2c_intr,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ i2c_master__DOT__state;
    CData/*6:0*/ i2c_master__DOT__saved_addr;
    CData/*0:0*/ i2c_master__DOT__i2c_scl_enable;
    CData/*0:0*/ i2c_master__DOT__intr_done;
    CData/*0:0*/ i2c_master__DOT___GEN_44;
    CData/*2:0*/ i2c_master__DOT___GEN_61;
    SData/*14:0*/ i2c_master__DOT__count;
    SData/*14:0*/ i2c_master__DOT___GEN_5;
    SData/*14:0*/ i2c_master__DOT___GEN_43;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vi2c_master__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vi2c_master);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vi2c_master(VerilatedContext* contextp, const char* name = "TOP");
    Vi2c_master(const char* name = "TOP")
      : Vi2c_master(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vi2c_master();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vi2c_master__Syms* __restrict vlSymsp);
    void __Vconfigure(Vi2c_master__Syms* symsp, bool first);
  private:
    static QData _change_request(Vi2c_master__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vi2c_master__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vi2c_master__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vi2c_master__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vi2c_master__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vi2c_master__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vi2c_master__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vi2c_master__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
