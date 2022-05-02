import chisel3._
import chisel3 . util._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation

class topTest extends FreeSpec with ChiselScalatestTester {

  "I2C top Test" in {
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

        val addr_bit1 = true.B 
        val addr_bit2 = true.B 
        val addr_bit3 = false.B 
        val addr_bit4 = false.B 
        val addr_bit5 = false.B 
        val addr_bit6 = true.B 
        val addr_bit7 = true.B 

        c.io.we.poke(1.B)  //write enable
        c.clock.step(1)

        c.io.addr.poke(4.U)   
        c.clock.step(1) 
        c.io.wdata.poke(99.U)   //1100011
        c.clock.step(1)

        c.io.addr.poke(8.U)
        c.clock.step(1)
        c.io.wdata.poke(0.U)
        c.clock.step(1)

        c.io.addr.poke(0.U)
        c.clock.step(1)
        c.io.wdata.poke(1.U) //01101101
        c.clock.step(1)

        c.clock.step(2)
        println(c.io.sda.peek())
        val addr_bit1_peek = c.io.sda.peek()        //peek address bits from sda output
        c.clock.step(1)
        println(c.io.sda.peek())
        val addr_bit2_peek = c.io.sda.peek()
        c.clock.step(1)
        println(c.io.sda.peek())
        val addr_bit3_peek = c.io.sda.peek()
        c.clock.step(1)
        println(c.io.sda.peek())
        val addr_bit4_peek = c.io.sda.peek()
        c.clock.step(1)
        println(c.io.sda.peek())
        val addr_bit5_peek = c.io.sda.peek()
        c.clock.step(1)
        println(c.io.sda.peek())
        val addr_bit6_peek = c.io.sda.peek()
        c.clock.step(1)
        println(c.io.sda.peek())
        val addr_bit7_peek = c.io.sda.peek()

        if(addr_bit1_peek.litValue == addr_bit1.litValue & addr_bit2_peek.litValue == addr_bit2.litValue
        & addr_bit3_peek.litValue == addr_bit3.litValue & addr_bit4_peek.litValue == addr_bit4.litValue
        & addr_bit5_peek.litValue == addr_bit5.litValue & addr_bit6_peek.litValue == addr_bit6.litValue
        & addr_bit7_peek.litValue == addr_bit7.litValue){
          
          c.io.addr.poke(12.U)
          // c.clock.step(1)
          c.io.wdata.poke(0.U)
          c.clock.step(1)

          println("Address matches")

          c.io.addr.poke(16.U)
          c.clock.step(1)
          c.io.wdata.poke(185.U) //01101101
          c.clock.step(1)

          c.io.addr.poke(0.U)
          c.clock.step(1)
          c.io.wdata.poke(0.U) //01101101
          c.clock.step(5)

          c.io.addr.poke(12.U)
          c.clock.step(1)
          c.io.wdata.poke(0.U)
          c.clock.step(1)

          

          
        } else{

          c.io.addr.poke(12.U)
          c.clock.step(1)
          c.io.wdata.poke(1.U)
          c.clock.step(1)

          println("Address not matches")

          c.io.addr.poke(0.U)
          c.clock.step(1)
          c.io.wdata.poke(0.U) //01101101
          c.clock.step(1)

        }

        // c.io.addr.poke(12.U)
        // c.clock.step(1)
        // c.io.wdata.poke(0.U)
        // c.clock.step(1)


          

          // c.io.addr.poke(16.U)
          // c.clock.step(1)
          // c.io.wdata.poke(185.U) //01101101
          // c.clock.step(9)

          // c.io.addr.poke(12.U)
          // c.clock.step(1)
          // c.io.wdata.poke(0.U)
          // c.clock.step(1)

          // c.io.addr.poke(0.U)
          // c.clock.step(1)
          // c.io.wdata.poke(0.U) //01101101
          // c.clock.step(1)

          

          c.clock.step(100)




    }
  }
}