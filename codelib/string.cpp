/*
 * string常见操作
 *
 */

///<逆转
string s = "I am a student.";

std:: void reverse(s.begin(), s.end());///<原地反转

string s1 = "";
s1.assign(s.rbegin(), s.rend());///<反转到s1里面
