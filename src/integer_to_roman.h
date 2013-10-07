class Solution {
private:
	string digit2roman(int digit, int baseindex, char *map){
		string res;
		if(digit <= 3){
			res.assign(digit, map[baseindex]);
		}else if(digit == 4){
			res += map[baseindex];
			res += map[baseindex+1];
		}else if(digit ==5){
			res += map[baseindex+1];
		}else if(digit <=8){
			res += map[baseindex+1];
			res.append(digit-5, map[baseindex]);
		}else{
			res += map[baseindex];
			res += map[baseindex+2];
		}
		return res;
	}
public:
	string intToRoman(int num) {
		string res;
		//				1    5   10   50   100  500 1000
		char map[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		int scale = 1000;
		for(int i = 6; i>=0; i-=2){
			res += digit2roman(num/scale, i, map);
			num %= scale;
			scale /= 10;
		}
		return res;
	}
};
