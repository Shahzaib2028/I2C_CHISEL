// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VI2C_TOP_H_
#define _VI2C_TOP_H_  // guard

#include "verilated.h"

//==========

class VI2C_Top__Syms;
class VI2C_Top_VerilatedVcd;


//----------

VL_MODULE(VI2C_Top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_addr,6,0);
    VL_OUT8(io_sda,0,0);
    VL_OUT8(io_scl,0,0);
    VL_OUT8(io_intr,0,0);
    VL_IN(io_wdata,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ I2C_Top__DOT__addr_start_bit;
    CData/*6:0*/ I2C_Top__DOT__addr_slave_addr;
    CData/*7:0*/ I2C_Top__DOT__addr_data;
    CData/*0:0*/ I2C_Top__DOT__addr_read_write_bit;
    CData/*0:0*/ I2C_Top__DOT__addr_data_ack;
    CData/*0:0*/ I2C_Top__DOT___GEN_9;
    CData/*0:0*/ I2C_Top__DOT___GEN_11;
    CData/*0:0*/ I2C_Top__DOT___GEN_12;
    CData/*6:0*/ I2C_Top__DOT___GEN_13;
    CData/*7:0*/ I2C_Top__DOT___GEN_14;
    CData/*7:0*/ I2C_Top__DOT__i2c__DOT__state;
    CData/*0:0*/ I2C_Top__DOT__i2c__DOT__i2c_scl_enable;
    CData/*0:0*/ I2C_Top__DOT__i2c__DOT__intr_done;
    CData/*0:0*/ I2C_Top__DOT__i2c__DOT___GEN_34;
    CData/*2:0*/ I2C_Top__DOT__i2c__DOT___GEN_51;
    SData/*14:0*/ I2C_Top__DOT__i2c__DOT__count;
    SData/*14:0*/ I2C_Top__DOT__i2c__DOT___GEN_5;
    SData/*14:0*/ I2C_Top__DOT__i2c__DOT___GEN_33;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VI2C_Top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VI2C_Top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VI2C_Top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VI2C_Top();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VI2C_Top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VI2C_Top__Syms* symsp, bool first);
  private:
    static QData _change_request(VI2C_Top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VI2C_Top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VI2C_Top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VI2C_Top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VI2C_Top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VI2C_Top__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VI2C_Top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
