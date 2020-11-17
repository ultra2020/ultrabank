#include <eosiolib/eosio.hpp>
using namespace eosio;
using std::string;
using std::vector;

struct extension2 {
	string c;
	string d;
};


struct extension {
	string a;
	string b;
	vector<extension2> ext2;
};

struct address
  {
    uint64_t id;
    string   name;
    uint8_t  age;
    uint64_t phonenumber;
    string   address;
    vector<extension> ext;
    //extension ext;
};

CONTRACT addressbook : public eosio::contract
{
public:
  //uint64_t SCOPE = _self.value;
  using contract::contract;

public:
  TABLE addressbook_t
  {
    uint64_t id;
    string   name;         
    uint8_t  age;                 
    uint64_t phonenumber;
    string   address;
  
    uint64_t primary_key() const {return id;}
    uint64_t by_phonenumber() const {return phonenumber;}
  };


public:
  typedef eosio::multi_index<name("addressbook"), addressbook_t,
                             indexed_by<name("phonenumber"), const_mem_fun<addressbook_t, uint64_t, &addressbook_t::by_phonenumber>>
                            >addressbooks_t;

  ACTION add( name account, string name, uint8_t age,  uint64_t phonenumber, string address);
  ACTION remove(name account, uint64_t id);
  ACTION update(name account, uint64_t id, string name, uint8_t age,  uint64_t phonenumber, string address);
  ACTION clean( name account, int32_t batch_size);
// public:
//   template <typename T>
//   void print_rows(T & itr, T & itr_end, int32_t limit)
//   {
//     int32_t i = 0;
//     if (limit <= 0)
//       limit = (std::numeric_limits<int32_t>::max)();
//     for (; itr != itr_end && i < limit; itr++, i++)
//     {
//       print("________________________________________");
//       print("\nid: ", itr->id,
//             "\naccount: ", itr->name,
//             "\nquantity: ", itr->age,
//             "\nfrom: ", itr->phonenumber,
//             "\nto: ", itr->address);
//       print("\n");
//     }
//   };
};
