import chisel3._
import chisel3 . util._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class topTest extends FreeSpec with ChiselScalatestTester {

  "I2C Test" in {
    test(new I2C_Top()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>    

        
      

        // c.io.addr.poke(6.U)
        // c.io.data.poke(135.U)
        // c.io.read_write.poke(1.B)
        // c.io.start.poke(1.B)
        // c.io.i2c_sda_in.poke(1.B)
        // c.clock.step(100)

        // c.io.sda_in.poke(1.B)
        // c.clock.step(1)
        // c.io.sda_in.poke(1.B)
        // c.clock.step(1)
        // c.io.sda_in.poke(0.B)
        // c.clock.step(1)
        // c.io.sda_in.poke(0.B)
        // c.clock.step(1)
        // c.io.sda_in.poke(1.B)
        // c.clock.step(1)
        // c.io.sda_in.poke(0.B)
        // c.clock.step(1)
        // c.io.sda_in.poke(0.B)
        // c.clock.step(100)

        c.io.we.poke(1.B)  //write enable
        c.clock.step(1)

        c.io.addr.poke(4.U)   
        c.clock.step(1) 
        c.io.wdata.poke(99.U)   //1001110
        c.clock.step(1)

        c.io.addr.poke(8.U)
        c.clock.step(1)
        c.io.wdata.poke(0.U)
        c.clock.step(1)


          c.io.addr.poke(0.U)
          c.clock.step(1)
          c.io.wdata.poke(1.U) //01101101
          c.clock.step(1)

          c.io.addr.poke(16.U)
          c.clock.step(1)
          c.io.wdata.poke(185.U) //01101101
          c.clock.step(1)

          c.io.addr.poke(0.U)
          c.clock.step(1)
          c.io.wdata.poke(0.U) //01101101
          c.clock.step(1)

          

          c.clock.step(100)




    }
  }
}