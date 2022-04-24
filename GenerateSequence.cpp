

#include <iostream>
#include <fstream>
#include <bitset>
#define COUNT_BITS 8

void bitSet_add_1(std::bitset<COUNT_BITS>& bSet) {
   
    for (int i = 0; i < COUNT_BITS; i++) {
        if (bSet[i] == 0) {
            bSet[i] = 1;
            std::cout << bSet << "\n";
            return;
        }
        else {
            bSet[i] = 0;
        }
    }
}

char* convertBitSetInByte(std::bitset<COUNT_BITS>& bSet) {
    std::bitset<COUNT_BITS> mask(0xff);;
    char result[COUNT_BITS / 8];
    for (int i = 0; i < COUNT_BITS / 8; ++i) {
        auto byte =
            static_cast<char>(((bSet >> (8 * i)) & mask).to_ulong());
        result[i] = byte;
        
    }
    return result;
}

int main()
{
    std::bitset<COUNT_BITS> b48;
    b48.reset();
    std::ofstream fileResult("result_qwe.enc", std::ios::out | std::ios::binary);
    
    for (int i = 0; i < 8; i++) {

        char* ref = convertBitSetInByte(b48);
        std::cout << "+++ " << std::hex << static_cast<int>(*ref) << std::endl;
        fileResult.write(ref, COUNT_BITS / 8);
        
        bitSet_add_1(b48);
       // std::cout << sizeof(b48) <<"\n";
    }

    
    fileResult.close();
    //std::cout << b48.count();

}


