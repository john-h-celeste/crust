#include <iostream>
#include <string>
#include <vector>

bool isVowel(char c) {
    return (
        c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u' ||
        c == 'A' ||
        c == 'E' ||
        c == 'I' ||
        c == 'O' ||
        c == 'U'
    );
}

std::string reverseWithVowels(std::string s) {
    std::string s2(s.length(), '_');
    std::vector<char> v;

    std::cout << s2 << std::endl;

    for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--) {
        s2[i] = s[j];
        if (isVowel(s[j])) {
            v.push_back(s[j]);
        }
    }

    std::cout << s2 << std::endl;

    for (int i = s.length() - 1, j = 0; i >= 0; i--) {
        if (isVowel(s2[i])) {
            s2[i] = v[j];
            j++;
        }
    }

    return s2;
}

int main(void) {
    std::string s(
        "90 - 40:sArutciL)2.11 retpihC( sceseB ratneoP ,)"
        "7.21 ,6.21( sritcoV ,)7 ratpehC( syurri ,)6-ritp"
        "ohC( snuetcneF ,)5-ratpahC( spaeL ,)4-ritpehC( s"
        "gnertS dne sratcurihC:sratpohC kiubtxeT)doksa ab"
        " llaw snuetsioq01( .skrim 01 :skreM lateT.setono"
        "m 02 raf ,sselCgnarad ,)yedsandiW( 5202/12/50 :a"
        "meT & otoD .ssalc yedsundiW roa ne 2 zAaQ aveh e"
        "tgnoog ire aw ,ridnamer kceuq e"
    );
    s = reverseWithVowels(s);
    std::cout << s << std::endl;
    return 0;
}