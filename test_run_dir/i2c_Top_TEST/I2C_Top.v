module i2c_master(
  input        clock,
  input        reset,
  input        io_start,
  input  [6:0] io_addr,
  input  [7:0] io_data,
  input        io_read_write,
  input        io_data_ack,
  output       io_i2c_sda,
  output       io_i2c_scl
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] state; // @[i2c_master.scala 25:24]
  reg [14:0] count; // @[i2c_master.scala 26:24]
  reg  i2c_scl_enable; // @[i2c_master.scala 29:33]
  wire  _GEN_0 = state == 8'h0 | state == 8'h1 | state == 8'h6 ? 1'h0 : 1'h1; // @[i2c_master.scala 53:87 i2c_master.scala 54:28 i2c_master.scala 56:29]
  wire  _GEN_1 = reset ? 1'h0 : _GEN_0; // @[i2c_master.scala 50:22 i2c_master.scala 51:24]
  wire  _T_7 = 8'h0 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_2 = io_start ? 3'h1 : 3'h0; // @[i2c_master.scala 67:39 i2c_master.scala 68:27 i2c_master.scala 72:27]
  wire  _T_9 = 8'h1 == state; // @[Conditional.scala 37:30]
  wire  _T_10 = 8'h2 == state; // @[Conditional.scala 37:30]
  wire [6:0] _io_i2c_sda_T = io_addr >> count; // @[i2c_master.scala 88:38]
  wire  _T_11 = count == 15'h0; // @[i2c_master.scala 91:28]
  wire [14:0] _count_T_1 = count - 15'h1; // @[i2c_master.scala 94:36]
  wire [2:0] _GEN_4 = count == 15'h0 ? 3'h3 : 3'h2; // @[i2c_master.scala 91:36 i2c_master.scala 92:27 i2c_master.scala 95:27]
  wire [14:0] _GEN_5 = count == 15'h0 ? count : _count_T_1; // @[i2c_master.scala 91:36 i2c_master.scala 26:24 i2c_master.scala 94:27]
  wire  _T_12 = 8'h3 == state; // @[Conditional.scala 37:30]
  wire  _GEN_6 = ~io_read_write ? 1'h0 : 1'h1; // @[i2c_master.scala 101:44 i2c_master.scala 102:32 i2c_master.scala 108:32]
  wire [3:0] _GEN_9 = ~io_read_write ? 4'h8 : 4'h7; // @[i2c_master.scala 101:44 i2c_master.scala 106:27 i2c_master.scala 112:27]
  wire  _T_14 = 8'h4 == state; // @[Conditional.scala 37:30]
  wire [7:0] _io_i2c_sda_T_2 = io_data >> count; // @[i2c_master.scala 119:38]
  wire [2:0] _GEN_10 = _T_11 ? 3'h5 : 3'h4; // @[i2c_master.scala 122:36 i2c_master.scala 123:27 i2c_master.scala 126:27]
  wire  _T_16 = 8'h5 == state; // @[Conditional.scala 37:30]
  wire  _GEN_15 = _T_16 ? io_data_ack : 1'h1; // @[Conditional.scala 39:67 i2c_master.scala 132:28]
  wire [2:0] _GEN_17 = _T_16 ? 3'h6 : 3'h0; // @[Conditional.scala 39:67 i2c_master.scala 135:23]
  wire  _GEN_18 = _T_14 ? _io_i2c_sda_T_2[0] : _GEN_15; // @[Conditional.scala 39:67 i2c_master.scala 119:28]
  wire [2:0] _GEN_20 = _T_14 ? _GEN_10 : _GEN_17; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_21 = _T_14 ? _GEN_5 : count; // @[Conditional.scala 39:67 i2c_master.scala 26:24]
  wire  _GEN_22 = _T_12 ? _GEN_6 : _GEN_18; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_24 = _T_12 ? 3'h4 : _GEN_20; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_25 = _T_12 ? {{11'd0}, _GEN_9} : _GEN_21; // @[Conditional.scala 39:67]
  wire  _GEN_26 = _T_10 ? _io_i2c_sda_T[0] : _GEN_22; // @[Conditional.scala 39:67 i2c_master.scala 88:28]
  wire [2:0] _GEN_28 = _T_10 ? _GEN_4 : _GEN_24; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_29 = _T_10 ? _GEN_5 : _GEN_25; // @[Conditional.scala 39:67]
  wire  _GEN_30 = _T_9 ? 1'h0 : _GEN_26; // @[Conditional.scala 39:67 i2c_master.scala 78:28]
  wire [2:0] _GEN_33 = _T_9 ? 3'h2 : _GEN_28; // @[Conditional.scala 39:67 i2c_master.scala 83:23]
  wire  _GEN_35 = _T_7 | _GEN_30; // @[Conditional.scala 40:58 i2c_master.scala 66:28]
  wire [2:0] _GEN_36 = _T_7 ? _GEN_2 : _GEN_33; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_40 = reset ? 3'h0 : _GEN_36; // @[i2c_master.scala 60:22 i2c_master.scala 61:15]
  assign io_i2c_sda = reset | _GEN_35; // @[i2c_master.scala 60:22 i2c_master.scala 62:20]
  assign io_i2c_scl = ~i2c_scl_enable | ~clock; // @[i2c_master.scala 48:22]
  always @(posedge clock) begin
    if (reset) begin // @[i2c_master.scala 25:24]
      state <= 8'h0; // @[i2c_master.scala 25:24]
    end else begin
      state <= {{5'd0}, _GEN_40};
    end
    if (reset) begin // @[i2c_master.scala 26:24]
      count <= 15'h0; // @[i2c_master.scala 26:24]
    end else if (!(reset)) begin // @[i2c_master.scala 60:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          count <= 15'h6; // @[i2c_master.scala 84:23]
        end else begin
          count <= _GEN_29;
        end
      end
    end
    i2c_scl_enable <= reset | _GEN_1; // @[i2c_master.scala 29:33 i2c_master.scala 29:33]
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
  i2c_scl_enable = _RAND_2[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module I2C_Top(
  input         clock,
  input         reset,
  input  [31:0] io_wdata,
  input  [6:0]  io_addr,
  output        io_sda,
  output        io_scl
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  wire  i2c_clock; // @[I2C_Top.scala 52:21]
  wire  i2c_reset; // @[I2C_Top.scala 52:21]
  wire  i2c_io_start; // @[I2C_Top.scala 52:21]
  wire [6:0] i2c_io_addr; // @[I2C_Top.scala 52:21]
  wire [7:0] i2c_io_data; // @[I2C_Top.scala 52:21]
  wire  i2c_io_read_write; // @[I2C_Top.scala 52:21]
  wire  i2c_io_data_ack; // @[I2C_Top.scala 52:21]
  wire  i2c_io_i2c_sda; // @[I2C_Top.scala 52:21]
  wire  i2c_io_i2c_scl; // @[I2C_Top.scala 52:21]
  reg  addr_start_bit; // @[I2C_Top.scala 23:33]
  reg [6:0] addr_slave_addr; // @[I2C_Top.scala 24:34]
  reg [7:0] addr_data; // @[I2C_Top.scala 25:28]
  reg  addr_read_write_bit; // @[I2C_Top.scala 26:38]
  reg  addr_data_ack; // @[I2C_Top.scala 28:32]
  wire  _GEN_0 = io_addr == 7'h14 ? io_wdata[0] : addr_data_ack; // @[I2C_Top.scala 42:42 I2C_Top.scala 43:23 I2C_Top.scala 28:32]
  wire  _GEN_1 = io_addr == 7'h14 & addr_start_bit; // @[I2C_Top.scala 42:42 I2C_Top.scala 23:33 I2C_Top.scala 45:24]
  wire [6:0] _GEN_2 = io_addr == 7'h14 ? addr_slave_addr : 7'h0; // @[I2C_Top.scala 42:42 I2C_Top.scala 24:34 I2C_Top.scala 46:25]
  wire [7:0] _GEN_3 = io_addr == 7'h14 ? addr_data : 8'h0; // @[I2C_Top.scala 42:42 I2C_Top.scala 25:28 I2C_Top.scala 47:19]
  wire  _GEN_5 = io_addr == 7'hc ? addr_data_ack : _GEN_0; // @[I2C_Top.scala 40:37 I2C_Top.scala 28:32]
  wire  _GEN_6 = io_addr == 7'hc ? addr_start_bit : _GEN_1; // @[I2C_Top.scala 40:37 I2C_Top.scala 23:33]
  wire [6:0] _GEN_7 = io_addr == 7'hc ? addr_slave_addr : _GEN_2; // @[I2C_Top.scala 40:37 I2C_Top.scala 24:34]
  wire [7:0] _GEN_8 = io_addr == 7'hc ? addr_data : _GEN_3; // @[I2C_Top.scala 40:37 I2C_Top.scala 25:28]
  wire  _GEN_9 = io_addr == 7'h8 ? io_wdata[0] : addr_read_write_bit; // @[I2C_Top.scala 38:48 I2C_Top.scala 39:29 I2C_Top.scala 26:38]
  wire  _GEN_11 = io_addr == 7'h8 ? addr_data_ack : _GEN_5; // @[I2C_Top.scala 38:48 I2C_Top.scala 28:32]
  wire  _GEN_12 = io_addr == 7'h8 ? addr_start_bit : _GEN_6; // @[I2C_Top.scala 38:48 I2C_Top.scala 23:33]
  wire [6:0] _GEN_13 = io_addr == 7'h8 ? addr_slave_addr : _GEN_7; // @[I2C_Top.scala 38:48 I2C_Top.scala 24:34]
  wire [7:0] _GEN_14 = io_addr == 7'h8 ? addr_data : _GEN_8; // @[I2C_Top.scala 38:48 I2C_Top.scala 25:28]
  i2c_master i2c ( // @[I2C_Top.scala 52:21]
    .clock(i2c_clock),
    .reset(i2c_reset),
    .io_start(i2c_io_start),
    .io_addr(i2c_io_addr),
    .io_data(i2c_io_data),
    .io_read_write(i2c_io_read_write),
    .io_data_ack(i2c_io_data_ack),
    .io_i2c_sda(i2c_io_i2c_sda),
    .io_i2c_scl(i2c_io_i2c_scl)
  );
  assign io_sda = i2c_io_i2c_sda; // @[I2C_Top.scala 60:12]
  assign io_scl = i2c_io_i2c_scl; // @[I2C_Top.scala 61:12]
  assign i2c_clock = clock;
  assign i2c_reset = reset;
  assign i2c_io_start = addr_start_bit; // @[I2C_Top.scala 53:18]
  assign i2c_io_addr = addr_slave_addr; // @[I2C_Top.scala 54:17]
  assign i2c_io_data = addr_data; // @[I2C_Top.scala 55:17]
  assign i2c_io_read_write = addr_read_write_bit; // @[I2C_Top.scala 56:23]
  assign i2c_io_data_ack = addr_data_ack; // @[I2C_Top.scala 58:21]
  always @(posedge clock) begin
    if (reset) begin // @[I2C_Top.scala 23:33]
      addr_start_bit <= 1'h0; // @[I2C_Top.scala 23:33]
    end else if (io_addr == 7'h0) begin // @[I2C_Top.scala 32:37]
      addr_start_bit <= io_wdata[0]; // @[I2C_Top.scala 33:24]
    end else if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 34:44]
      if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 36:38]
        addr_start_bit <= _GEN_12;
      end
    end
    if (reset) begin // @[I2C_Top.scala 24:34]
      addr_slave_addr <= 7'h0; // @[I2C_Top.scala 24:34]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 32:37]
      if (io_addr == 7'h4) begin // @[I2C_Top.scala 34:44]
        addr_slave_addr <= io_wdata[6:0]; // @[I2C_Top.scala 35:25]
      end else if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 36:38]
        addr_slave_addr <= _GEN_13;
      end
    end
    if (reset) begin // @[I2C_Top.scala 25:28]
      addr_data <= 8'h0; // @[I2C_Top.scala 25:28]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 32:37]
      if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 34:44]
        if (io_addr == 7'h10) begin // @[I2C_Top.scala 36:38]
          addr_data <= io_wdata[7:0]; // @[I2C_Top.scala 37:19]
        end else begin
          addr_data <= _GEN_14;
        end
      end
    end
    if (reset) begin // @[I2C_Top.scala 26:38]
      addr_read_write_bit <= 1'h0; // @[I2C_Top.scala 26:38]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 32:37]
      if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 34:44]
        if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 36:38]
          addr_read_write_bit <= _GEN_9;
        end
      end
    end
    if (reset) begin // @[I2C_Top.scala 28:32]
      addr_data_ack <= 1'h0; // @[I2C_Top.scala 28:32]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 32:37]
      if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 34:44]
        if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 36:38]
          addr_data_ack <= _GEN_11;
        end
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
  addr_start_bit = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  addr_slave_addr = _RAND_1[6:0];
  _RAND_2 = {1{`RANDOM}};
  addr_data = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  addr_read_write_bit = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  addr_data_ack = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
