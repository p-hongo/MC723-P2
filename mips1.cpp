/******************************************************
 * Processor Module Implementation File.              *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/
 

#include  "mips1.H"
#include  "mips1_isa.cpp"

#include  "mips1_syscall.H"

int pipeline_size = 5;
int cycles = pipeline_size-1;
int cycles_lost_to_hazards = 0;

void mips1::behavior() {

  unsigned ins_id;
  cache_item_t* ins_cache;
  if (has_delayed_load) {
    APP_MEM->load(delayed_load_program);
    ac_pc = ac_start_addr;
    has_delayed_load = false;
  }

  for (;;) {

  bhv_pc = ac_pc;
  if( bhv_pc >= dec_cache_size){
    cerr << "ArchC: Address out of bounds (pc=0x" << hex << bhv_pc << ")." << endl;
    stop();
    return;
  }
  else {
    if( start_up ){
      decode_pc = ac_pc;
      ISA.syscall.set_prog_args(argc, argv);
      start_up=0;
      init_dec_cache();
    }
    else{ 
      decode_pc = bhv_pc;
    }
 
    //!Handling System calls.
    switch( decode_pc ){

#define AC_SYSC(NAME,LOCATION) \
    case LOCATION: \
        ISA.syscall.NAME(); \
      break;  \


#include <ac_syscall.def>

#undef AC_SYSC

    default:

      ins_cache = (DEC_CACHE+decode_pc);
      if ( !ins_cache->valid ){
        quant = 0;
        ins_cache->instr_p = new ac_instr<mips1_parms::AC_DEC_FIELD_NUMBER>((ISA.decoder)->Decode(reinterpret_cast<unsigned char*>(buffer), quant));
        ins_cache->valid = 1;
      }
      instr_vec = ins_cache->instr_p;
      ins_id = instr_vec->get(IDENT);

      if( ins_id == 0 ) {
        cerr << "ArchC Error: Unidentified instruction. " << endl;
        cerr << "PC = " << hex << decode_pc << dec << endl;
        stop();
        return;
      }

      ac_pc = decode_pc;

      ++cycles;

      detect_data_hazard();

      ISA.cur_instr_id = ins_id;
      if (!ac_annul_sig) ISA._behavior_instruction(instr_vec->get(1));   

      //get_mem_cache_misses(ac_annul_sig, ins_id, instr_vec, mem_cache);

      switch (ins_id) {
      case 1: // Instruction lb
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lb(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 2: // Instruction lbu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lbu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 3: // Instruction lh
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lh(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 4: // Instruction lhu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lhu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 5: // Instruction lw
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lw(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 6: // Instruction lwl
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lwl(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 7: // Instruction lwr
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lwr(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 8: // Instruction sb
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_sb(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 9: // Instruction sh
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_sh(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 10: // Instruction sw
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_sw(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 11: // Instruction swl
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_swl(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 12: // Instruction swr
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_swr(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 13: // Instruction addi
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_addi(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 14: // Instruction addiu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_addiu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 15: // Instruction slti
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_slti(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 16: // Instruction sltiu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_sltiu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 17: // Instruction andi
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_andi(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 18: // Instruction ori
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_ori(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 19: // Instruction xori
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_xori(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 20: // Instruction lui
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_lui(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 21: // Instruction add
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_add(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 22: // Instruction addu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_addu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 23: // Instruction sub
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_sub(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 24: // Instruction subu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_subu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 25: // Instruction slt
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_slt(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 26: // Instruction sltu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_sltu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 27: // Instruction instr_and
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_instr_and(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 28: // Instruction instr_or
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_instr_or(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 29: // Instruction instr_xor
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_instr_xor(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 30: // Instruction instr_nor
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_instr_nor(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 31: // Instruction nop
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_nop(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 32: // Instruction sll
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_sll(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 33: // Instruction srl
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_srl(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 34: // Instruction sra
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_sra(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 35: // Instruction sllv
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_sllv(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 36: // Instruction srlv
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_srlv(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 37: // Instruction srav
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_srav(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 38: // Instruction mult
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_mult(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 39: // Instruction multu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_multu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 40: // Instruction div
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_div(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 41: // Instruction divu
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_divu(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 42: // Instruction mfhi
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_mfhi(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 43: // Instruction mthi
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_mthi(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 44: // Instruction mflo
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_mflo(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 45: // Instruction mtlo
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_mtlo(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 46: // Instruction j
	++cycles;
        if (!ac_annul_sig) ISA._behavior_mips1_Type_J(instr_vec->get(1), instr_vec->get(8));
        if (!ac_annul_sig) ISA.behavior_j(instr_vec->get(1), instr_vec->get(8));
        break;
      case 47: // Instruction jal
	++cycles;
        if (!ac_annul_sig) ISA._behavior_mips1_Type_J(instr_vec->get(1), instr_vec->get(8));
        if (!ac_annul_sig) ISA.behavior_jal(instr_vec->get(1), instr_vec->get(8));
        break;
      case 48: // Instruction jr
	++cycles;
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_jr(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 49: // Instruction jalr
	++cycles;
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_jalr(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 50: // Instruction beq
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_beq(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 51: // Instruction bne
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_bne(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 52: // Instruction blez
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_blez(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 53: // Instruction bgtz
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_bgtz(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 54: // Instruction bltz
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_bltz(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 55: // Instruction bgez
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_bgez(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 56: // Instruction bltzal
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_bltzal(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 57: // Instruction bgezal
        if (!ac_annul_sig) ISA._behavior_mips1_Type_I(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        if (!ac_annul_sig) ISA.behavior_bgezal(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(7));
        break;
      case 58: // Instruction sys_call
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_sys_call(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      case 59: // Instruction instr_break
        if (!ac_annul_sig) ISA._behavior_mips1_Type_R(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        if (!ac_annul_sig) ISA.behavior_instr_break(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3), instr_vec->get(4), instr_vec->get(5), instr_vec->get(6));
        break;
      } // switch (ins_id)
      break;
    }
    if ((!ac_wait_sig) && (!ac_annul_sig)) ac_instr_counter+=1;
    ac_annul_sig = 0;
    previous_instruction[0] = previous_instruction[1];
    previous_instruction[1] = instr_vec;
  }
//!Updating Regs for behavioral simulation.
  if(!ac_wait_sig){
    bhv_pc = ac_pc;
  }
  if (ac_stop_flag) {
    return;
  }
  else {
    if (instr_in_batch < instr_batch_size) {
      instr_in_batch++;
    }
    else {
      instr_in_batch = 0;
      wait(1, SC_NS);
    }
  }

} // for (;;)
} // behavior()

bool mips1::has_load_read_dependency(ac_instr_t *load, ac_instr_t *instruction) {
    if (!(load->get(IDENT) >= 1 && load->get(IDENT) <= 7)) {
        return false; // not a load
    }

    int op = instruction->get(IDENT);
    int load_rt = load->get(3);

    int rs = 0, rt = 0;
    if (op >= 13 && op <= 20) {
        // type I instructions read from Rs
        rs = instruction->get(2);
    } else if (op >= 21 && op <= 45) {
        // type R instructions read Rs and Rt
        rs = instruction->get(2);
        rt = instruction->get(3);
    } else if (op == 48 || op == 49) {
        // jr and jalr read from Rs
        rs = instruction->get(2);
    } else if (op >= 50 && op <= 57) {
        // branch instructions need Rs and Rt
        rs = instruction->get(2);
        rt = instruction->get(3);
    }

    if (load_rt && (load_rt == rs || load_rt == rt)) {
        return true;
    }

    return false;
}

d4cache* mips1::set_mem_cache() {
    d4cache* Mem;
    d4cache* L1;
    char *name = new char[20];
    strcpy(name, "Mem");

    Mem = d4new(NULL);
    L1 = d4new(Mem);
    L1->name = name;
    L1->flags = D4F_CCC;
    L1->lg2blocksize = 9;
    L1->lg2subblocksize = 9;
    L1->lg2size = 17;
    L1->assoc = 1;
    L1->replacementf = d4rep_lru;
    L1->prefetchf = d4prefetch_none;
    L1->wallocf = d4walloc_always;
    L1->wbackf = d4wback_never;
    L1->name_replacement = L1->name_prefetch = L1->name_walloc = L1->name_wback = name;
    
    return L1;
}

d4cache* mips1::set_ins_cache() {
    d4cache* Mem;
    d4cache* L1;
    char *name = new char[20];
    strcpy(name, "Instr");

    Mem = d4new(NULL);
    L1 = d4new(Mem);
    L1->name = name;
    L1->flags = D4F_CCC | D4F_RO;
    L1->lg2blocksize = 9;
    L1->lg2subblocksize = 9;
    L1->lg2size = 17;
    L1->assoc = 1;
    L1->replacementf = d4rep_lru;
    L1->prefetchf = d4prefetch_none;
    L1->wallocf = d4walloc_always;
    L1->wbackf = d4wback_never;
    L1->name_replacement = L1->name_prefetch = L1->name_walloc = L1->name_wback = name;
    
    return L1;
}

/*void mips1::get_mem_cache_misses(int ac_annul_sig, int ins_id, mips1::ac_instr_t* instr_vec, d4cache *cache){
    
    if(!ac_annul_sig && ins_id == 1 || ins_id == 2){
        R.address = (d4addr) (RB[instr_vec->get(2)] + instr_vec->get(7));
        R.size = sizeof(char);
        R.accesstype = D4XREAD;
        d4ref(mem_cache, R);
    } 
    }*/

void mips1::print_cache_status(d4cache *L1) {
    std::cout << "\nCache " << L1->name << " misses:" << "\n";
    int misses = L1->miss[D4XREAD]
        + L1->miss[D4XWRITE]
        + L1->miss[D4XINSTRN]
        + L1->miss[D4XMISC]
        + L1->miss[D4XREAD+D4PREFETCH]
        + L1->miss[D4XWRITE+D4PREFETCH]
        + L1->miss[D4XINSTRN+D4PREFETCH]
        + L1->miss[D4XMISC+D4PREFETCH];
    int access = L1->fetch[D4XREAD]
        + L1->fetch[D4XWRITE]
        + L1->fetch[D4XINSTRN]
        + L1->fetch[D4XMISC]
        + L1->fetch[D4XREAD+D4PREFETCH]
        + L1->fetch[D4XWRITE+D4PREFETCH]
        + L1->fetch[D4XINSTRN+D4PREFETCH]
        + L1->fetch[D4XMISC+D4PREFETCH];
    int non_comp_misses = misses - L1->comp_miss[D4XWRITE] - L1->comp_miss[D4XREAD];
    double total_percentage = 100*(double)misses/(double)access;
    double non_comp_percentage = 100*(double)non_comp_misses/(double)access;
    std::cout << misses << " of " << access;
    std::cout << " (" <<  total_percentage << "\%" << " total)";
    std::cout << " (" << non_comp_percentage << "\%" <<" non-compulsory)"<< "\n";

    std::cout << "read misses: " <<  (int)L1->miss[D4XREAD] << "/" << (int)L1->fetch[D4XREAD];
    std::cout << " (" << (double)(100*(double)L1->miss[D4XREAD]/(double)L1->fetch[D4XREAD]) << "\%)\n";

    std::cout << "read non-comp misses: " <<  (int)(L1->miss[D4XREAD] - L1->comp_miss[D4XREAD]) << "/" << (int)L1->fetch[D4XREAD];
    std::cout << " (" << (double)(100*(double)(L1->miss[D4XREAD] - L1->comp_miss[D4XREAD])/(double)L1->fetch[D4XREAD]) << "\%)\n";

    std::cout << "write misses: " <<  (int)L1->miss[D4XWRITE] << "/" << (int)L1->fetch[D4XWRITE];
    std::cout << " (" << (double)(100*(double)L1->miss[D4XWRITE]/(double)L1->fetch[D4XWRITE]) << "\%)\n";

    std::cout << "write non-comp misses: " <<  (int)(L1->miss[D4XWRITE] - L1->comp_miss[D4XWRITE]) << "/" << (int)L1->fetch[D4XWRITE];
    std::cout << " (" << (double)(100*(double)(L1->miss[D4XREAD] - L1->comp_miss[D4XWRITE])/(double)L1->fetch[D4XWRITE]) << "\%)\n";

    std::cout << "compulsory misses: " << (int)(L1->comp_miss[D4XWRITE]+L1->comp_miss[D4XINSTRN]+L1->comp_miss[D4XMISC]+L1->comp_miss[D4XREAD]) << "\n";
    std::cout << "capacity misses: " <<  (int)(L1->cap_miss[D4XWRITE]+L1->cap_miss[D4XINSTRN]+L1->cap_miss[D4XMISC]+L1->cap_miss[D4XREAD]) << "\n";
    std::cout << "conflict misses: " <<  (int)(L1->conf_miss[D4XWRITE]+L1->conf_miss[D4XINSTRN]+L1->conf_miss[D4XMISC]+L1->conf_miss[D4XREAD]) << "\n\n";
}

void print_mispredictions() {
  
  std::cout << endl << "1-bit mispredictions: " << misprediction << endl;
  std::cout << "2-bit mispredictions: " << lmisprediction << endl << endl;

}

void mips1::detect_data_hazard() {
    // We assume forwarding for all pipeline stages, and that
    // branches are resolved in the EX step.
    // On a five stage pipeline, the only remaining case in which we
    // absolutely need to stall is a dependency between instructions
    // in the MEM and EX stages:
    //     lb $1, 0($2)
    //     add $4, $1, $5
    // This can only happen for loads on a five-stage pipeline, and in
    // that case, we need to stall for one cycle.
    // On our seven-stage pipeline:
    //     IF IS RF EX DF DS WB
    // we assume forwarding from DS to EX, and there are two cases that can
    // cause a hazard: the one above (2-cycle stall) and:
    //     lb $1, 0($2)
    //     ...any instruction...
    //     add $4, $1, $5
    // in which case we only need a 1-cycle stall.
    // The 13-stage pipeline:
    //     F1 F2 D0 D1 D2 D3 E0 E1 E2 E3 E4 E5
    // is similar to the 7-stage pipeline, assuming forwarding from E3 and E4 to
    // E1 and E2.

    // load $2, 0($3)
    // add $4, $2, 7
    if (previous_instruction[1] &&
        has_load_read_dependency(previous_instruction[1], instr_vec)) {

        if (pipeline_size == 5) {
            cycles += 1;
            cycles_lost_to_hazards += 1;
        } else if (pipeline_size == 7 || pipeline_size == 13) {
            cycles += 2;
            cycles_lost_to_hazards += 2;
        }
    }

    // load $2, 0($3)
    // sub $4, %5, $6
    // add $4, $2, 7
    if (previous_instruction[0] &&
        has_load_read_dependency(previous_instruction[0], instr_vec)) {

        // if instr_vec has a load-read dependency on previous_instruction[0],
        // and if previous_instruction[1] also has a load-read dependency on
        // previous_instruction[0], then we already stalled when
        // previous_instruction[1] entered the pipeline, and don't need to stall
        // again for instr_vec:
        //     lb $1, 0($2)
        //     add $4, $1, $3 <-- stall here because of $1
        //     add $5, $9, $1 <-- no need to stall here!

        bool stalled = has_load_read_dependency(previous_instruction[0],
                                                previous_instruction[1]);
        if ((pipeline_size == 7 || pipeline_size == 13) && !stalled) {
            cycles += 1;
            cycles_lost_to_hazards += 1;
        }
    }
}

 
#include <ac_sighandlers.H>

void mips1::init() {
  set_args(ac_argc, ac_argv);
#ifdef AC_VERIFY
  set_queue(av[0]);
#endif

  ac_pc = ac_start_addr;
  ISA._behavior_begin();
  cerr << "ArchC: -------------------- Starting Simulation --------------------" << endl;
  InitStat();

  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigint_handler);
  signal(SIGSEGV, sigsegv_handler);
  signal(SIGUSR1, sigusr1_handler);
#ifdef USE_GDB
  signal(SIGUSR2, sigusr2_handler);
#endif
#ifndef AC_COMPSIM
  set_running();
#else
  void Execute(int argc, char *argv[]);
  Execute(argc, argv);
#endif
}

void mips1::init(int ac, char *av[]) {
  extern char* appfilename;
  ac_init_opt( ac, av);
  ac_init_app( ac, av);
  APP_MEM->load(appfilename);
  set_args(ac_argc, ac_argv);
#ifdef AC_VERIFY
  set_queue(av[0]);
#endif

  ac_pc = ac_start_addr;
  ISA._behavior_begin();

  mem_cache = set_mem_cache();
  instr_cache = set_ins_cache();
  int r;
  if (0 != (r = d4setup())) {
      std::cerr << "Failed\n";
      abort();
  }
  
  cerr << "ArchC: -------------------- Starting Simulation --------------------" << endl;

  InitStat();

  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigint_handler);
  signal(SIGSEGV, sigsegv_handler);
  signal(SIGUSR1, sigusr1_handler);
#ifdef USE_GDB
  signal(SIGUSR2, sigusr2_handler);
#endif
#ifndef AC_COMPSIM
  set_running();
#else
  void Execute(int argc, char *argv[]);
  Execute(argc, argv);
#endif
}

//Stop simulation (may receive exit status)
void mips1::stop(int status) {
  cerr << "ArchC: -------------------- Simulation Finished --------------------" << endl;
  cerr << "\nNumber of cycles: " << cycles << endl;
  cerr << "Execution time: " << (double)(cycles)/(double)pipeline_size
       << endl;
  cerr << "Cycles lost to data hazards: " << cycles_lost_to_hazards << endl;
  print_cache_status(mem_cache);
  print_cache_status(instr_cache);
  print_mispredictions();
  ISA._behavior_end();
  ac_stop_flag = 1;
  ac_exit_status = status;
#ifndef AC_COMPSIM
  set_stopped();
#endif
}

void mips1::load(char* program) {
  APP_MEM->load(program);
}

void mips1::delayed_load(char* program) {
  has_delayed_load = true;
  delayed_load_program = new char[strlen(program)];
  strcpy(delayed_load_program, program);
}

// Returns ac_pc value
unsigned mips1::get_ac_pc() {
  return ac_pc;
}

// Assigns value to ac_pc
void mips1::set_ac_pc(unsigned int value) {
  ac_pc = value;
}

// Wrapper function to PrintStat().
void mips1::PrintStat() {
  ac_arch<mips1_parms::ac_word, mips1_parms::ac_Hword>::PrintStat();
}

