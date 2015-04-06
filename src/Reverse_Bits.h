class Solution {
    uint32_t m[256];
    uint32_t reverseBits_in(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i<8; i++){
            if((1<<i) & n) {
                res = res | (1 << (8-i-1));
            }
        }
        return res;
    }
public:
    Solution(){
        for(int i = 0; i<256; i++){
            m[i] = reverseBits_in(i);
        }
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i<4; i++){
            res = (res << 8) | m[((n >> (8*i)) & 255)];
        }
        return res;
    }
};

//class Solution {
//public:
//    uint32_t reverseBits(uint32_t n) {
//        uint32_t res = 0;
//        for(int i = 0; i<32; i++){
//            if((1<<i) & n) {
//                res = res | (1 << (32-i-1));
//            }
//        }
//        return res;
//    }
//};