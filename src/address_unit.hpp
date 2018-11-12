#include "interfaces.hpp"
#include<vector>
#include<queue>

using std::vector;
using std::queue;

class address_unit: public sc_module
{
public:
	sc_port<read_if_f> in_issue;
	sc_port<read_if> in_cdb;
	sc_port<write_if> out_slbuff;
	sc_port<write_if> out_rob;
	sc_port<read_if_f> in_rb;
	sc_port<write_if_f> out_rb;
	SC_HAS_PROCESS(address_unit);
	
	address_unit(sc_module_name name,unsigned int t);
	void leitura_issue();
	void leitura_cdb();
	void addr_issue();
	void leitura_rob();

private:
	struct addr_node
	{
		bool store;
		bool addr_calc;
		int regst;
		int rob_pos;
		unsigned int a;
	};
	string p;
	vector<string> ord,mem_ord;
	queue<addr_node> addr_queue;
	vector<addr_node> offset_buff;
	int regst,rg_i,rob_pos;
	unsigned int a,delay_time;
	sc_event addr_queue_event;

	vector<string> offset_split(string p);
	float ask_value(string reg);
	unsigned int ask_status(bool read,string reg,unsigned int pos = 0);
	void check_loads();
};