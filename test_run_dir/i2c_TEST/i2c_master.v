module i2c_master(
  input        clock,
  input        reset,
  input        io_start,
  input  [6:0] io_addr,
  input  [7:0] io_data,
  input        io_read_write,
  input        io_i2c_sda_in,
  output       io_i2c_sda,
  output       io_i2c_scl,
  output       io_ready,
  output       io_stop,
  output       io_i2c_intr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] state; // @[i2c_master.scala 24:24]
  reg [14:0] count; // @[i2c_master.scala 25:24]
  reg [6:0] saved_addr; // @[i2c_master.scala 26:29]
  reg  i2c_scl_enable; // @[i2c_master.scala 28:33]
  reg  intr_done; // @[i2c_master.scala 29:28]
  wire  _GEN_0 = state == 8'h0 | state == 8'h1 | state == 8'h7 ? 1'h0 : 1'h1; // @[i2c_master.scala 45:87 i2c_master.scala 46:28 i2c_master.scala 48:29]
  wire  _GEN_1 = reset ? 1'h0 : _GEN_0; // @[i2c_master.scala 42:22 i2c_master.scala 43:24]
  wire  _T_7 = 8'h0 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_2 = io_start ? 3'h1 : 3'h0; // @[i2c_master.scala 60:39 i2c_master.scala 61:27 i2c_master.scala 65:27]
  wire  _T_9 = 8'h1 == state; // @[Conditional.scala 37:30]
  wire  _T_10 = 8'h2 == state; // @[Conditional.scala 37:30]
  wire [6:0] _io_i2c_sda_T = saved_addr >> count; // @[i2c_master.scala 81:41]
  wire  _T_11 = count == 15'h0; // @[i2c_master.scala 84:28]
  wire [14:0] _count_T_1 = count - 15'h1; // @[i2c_master.scala 87:36]
  wire [2:0] _GEN_4 = count == 15'h0 ? 3'h3 : 3'h2; // @[i2c_master.scala 84:36 i2c_master.scala 85:27 i2c_master.scala 88:27]
  wire [14:0] _GEN_5 = count == 15'h0 ? count : _count_T_1; // @[i2c_master.scala 84:36 i2c_master.scala 25:24 i2c_master.scala 87:27]
  wire  _T_12 = 8'h3 == state; // @[Conditional.scala 37:30]
  wire  _T_13 = 8'h4 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_6 = ~io_i2c_sda_in ? 3'h5 : 3'h7; // @[i2c_master.scala 104:48 i2c_master.scala 105:31 i2c_master.scala 110:31]
  wire [14:0] _GEN_7 = ~io_i2c_sda_in ? 15'h7 : count; // @[i2c_master.scala 104:48 i2c_master.scala 106:31 i2c_master.scala 25:24]
  wire  _T_15 = 8'h5 == state; // @[Conditional.scala 37:30]
  wire [7:0] _io_i2c_sda_T_2 = io_data >> count; // @[i2c_master.scala 119:38]
  wire [2:0] _GEN_9 = _T_11 ? 3'h6 : 3'h5; // @[i2c_master.scala 122:36 i2c_master.scala 123:27 i2c_master.scala 126:27]
  wire  _T_17 = 8'h6 == state; // @[Conditional.scala 37:30]
  wire  _T_18 = 8'h7 == state; // @[Conditional.scala 37:30]
  wire  _GEN_12 = _T_18 | intr_done; // @[Conditional.scala 39:67 i2c_master.scala 140:27 i2c_master.scala 29:28]
  wire  _GEN_16 = _T_17 ? io_i2c_sda_in : 1'h1; // @[Conditional.scala 39:67 i2c_master.scala 132:28]
  wire  _GEN_18 = _T_17 ? 1'h0 : _T_18; // @[Conditional.scala 39:67 i2c_master.scala 134:25]
  wire [2:0] _GEN_19 = _T_17 ? 3'h7 : 3'h0; // @[Conditional.scala 39:67 i2c_master.scala 135:23]
  wire  _GEN_20 = _T_17 ? intr_done : _GEN_12; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_21 = _T_15 ? _io_i2c_sda_T_2[0] : _GEN_16; // @[Conditional.scala 39:67 i2c_master.scala 119:28]
  wire  _GEN_23 = _T_15 ? 1'h0 : _GEN_18; // @[Conditional.scala 39:67 i2c_master.scala 121:25]
  wire [2:0] _GEN_24 = _T_15 ? _GEN_9 : _GEN_19; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_25 = _T_15 ? _GEN_5 : count; // @[Conditional.scala 39:67 i2c_master.scala 25:24]
  wire  _GEN_26 = _T_15 ? intr_done : _GEN_20; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_27 = _T_13 ? io_i2c_sda_in : _GEN_21; // @[Conditional.scala 39:67 i2c_master.scala 103:32]
  wire [2:0] _GEN_28 = _T_13 ? _GEN_6 : _GEN_24; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_29 = _T_13 ? _GEN_7 : _GEN_25; // @[Conditional.scala 39:67]
  wire  _GEN_31 = _T_13 ? 1'h0 : _GEN_23; // @[Conditional.scala 39:67]
  wire  _GEN_32 = _T_13 ? intr_done : _GEN_26; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_33 = _T_12 ? io_read_write : _GEN_27; // @[Conditional.scala 39:67 i2c_master.scala 94:28]
  wire  _GEN_35 = _T_12 ? 1'h0 : _GEN_31; // @[Conditional.scala 39:67 i2c_master.scala 96:25]
  wire [2:0] _GEN_36 = _T_12 ? 3'h4 : _GEN_28; // @[Conditional.scala 39:67 i2c_master.scala 97:23]
  wire [14:0] _GEN_37 = _T_12 ? count : _GEN_29; // @[Conditional.scala 39:67 i2c_master.scala 25:24]
  wire  _GEN_38 = _T_12 ? intr_done : _GEN_32; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_39 = _T_10 ? _io_i2c_sda_T[0] : _GEN_33; // @[Conditional.scala 39:67 i2c_master.scala 81:28]
  wire  _GEN_41 = _T_10 ? 1'h0 : _GEN_35; // @[Conditional.scala 39:67 i2c_master.scala 83:25]
  wire [2:0] _GEN_42 = _T_10 ? _GEN_4 : _GEN_36; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_43 = _T_10 ? _GEN_5 : _GEN_37; // @[Conditional.scala 39:67]
  wire  _GEN_44 = _T_10 ? intr_done : _GEN_38; // @[Conditional.scala 39:67 i2c_master.scala 29:28]
  wire  _GEN_45 = _T_9 ? 1'h0 : _GEN_39; // @[Conditional.scala 39:67 i2c_master.scala 71:28]
  wire  _GEN_49 = _T_9 ? 1'h0 : _GEN_41; // @[Conditional.scala 39:67 i2c_master.scala 75:25]
  wire [2:0] _GEN_50 = _T_9 ? 3'h2 : _GEN_42; // @[Conditional.scala 39:67 i2c_master.scala 76:23]
  wire  _GEN_53 = _T_7 | _GEN_45; // @[Conditional.scala 40:58 i2c_master.scala 58:28]
  wire [2:0] _GEN_55 = _T_7 ? _GEN_2 : _GEN_50; // @[Conditional.scala 40:58]
  wire  _GEN_56 = _T_7 ? 1'h0 : _T_9; // @[Conditional.scala 40:58]
  wire  _GEN_57 = _T_7 ? 1'h0 : _GEN_49; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_61 = reset ? 3'h0 : _GEN_55; // @[i2c_master.scala 52:22 i2c_master.scala 53:15]
  assign io_i2c_sda = reset | _GEN_53; // @[i2c_master.scala 52:22 i2c_master.scala 54:20]
  assign io_i2c_scl = ~i2c_scl_enable | ~clock; // @[i2c_master.scala 40:22]
  assign io_ready = reset ? 1'h0 : _GEN_56; // @[i2c_master.scala 52:22 i2c_master.scala 34:14]
  assign io_stop = reset ? 1'h0 : _GEN_57; // @[i2c_master.scala 52:22 i2c_master.scala 35:13]
  assign io_i2c_intr = intr_done; // @[i2c_master.scala 148:17]
  always @(posedge clock) begin
    if (reset) begin // @[i2c_master.scala 24:24]
      state <= 8'h0; // @[i2c_master.scala 24:24]
    end else begin
      state <= {{5'd0}, _GEN_61};
    end
    if (reset) begin // @[i2c_master.scala 25:24]
      count <= 15'h0; // @[i2c_master.scala 25:24]
    end else if (!(reset)) begin // @[i2c_master.scala 52:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          count <= 15'h6; // @[i2c_master.scala 77:23]
        end else begin
          count <= _GEN_43;
        end
      end
    end
    if (reset) begin // @[i2c_master.scala 26:29]
      saved_addr <= 7'h0; // @[i2c_master.scala 26:29]
    end else if (!(reset)) begin // @[i2c_master.scala 52:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          saved_addr <= io_addr; // @[i2c_master.scala 72:28]
        end
      end
    end
    i2c_scl_enable <= reset | _GEN_1; // @[i2c_master.scala 28:33 i2c_master.scala 28:33]
    if (reset) begin // @[i2c_master.scala 29:28]
      intr_done <= 1'h0; // @[i2c_master.scala 29:28]
    end else if (!(reset)) begin // @[i2c_master.scala 52:22]
      if (_T_7) begin // @[Conditional.scala 40:58]
        intr_done <= 1'h0; // @[i2c_master.scala 59:27]
      end else if (!(_T_9)) begin // @[Conditional.scala 39:67]
        intr_done <= _GEN_44;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[7:0];
  _RAND_1 = {1{`RANDOM}};
  count = _RAND_1[14:0];
  _RAND_2 = {1{`RANDOM}};
  saved_addr = _RAND_2[6:0];
  _RAND_3 = {1{`RANDOM}};
  i2c_scl_enable = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  intr_done = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
