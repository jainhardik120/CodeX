#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
//     int minLength(unordered_map<string, vector<int>> &map, string beginWord, string endWord, vector<string> &wordList, vector<bool> &visited, vector<int> &result)
//     {
//         if (beginWord == endWord)
//         {
//             for (int i = 0; i < visited.size(); i++)
//             {
//                 if(visited[i]){
//                     cout << i << " ";
//                 }
//             }

//             return 0;
//         }
//         int min = INT_MAX;
//         bool flag = false;
//         for (auto i : map[beginWord])
//         {
//             if (!visited[i])
//             {
//                 visited[i] = true;
//                 int x;
//                 if (result[i] == -2)
//                 {
//                     x = minLength(map, wordList[i], endWord, wordList, visited, result);
//                     result[i] = x;
//                 }
//                 else
//                 {
//                     x = result[i];
//                 }
//                 visited[i] = false;
//                 if (x != -1)
//                 {
//                     flag = true;
//                     if (x < min)
//                     {
//                         min = x;
//                     }
//                 }
//             }
//         }
//         if (!flag)
//         {
//             return -1;
//         }
//         else
//         {
//             return 1 + min;
//         }
//     }

// public:
//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         unordered_map<string, vector<int>> map;
//         int n = wordList.size();
//         int len = beginWord.length();
//         for (int i = 0; i < n; i++)
//         {
//             int count = 0;
//             for (int k = 0; k < len; k++)
//             {
//                 if (wordList[i][k] != beginWord[k])
//                 {
//                     count++;
//                 }
//             }
//             if (count == 1)
//             {
//                 map[beginWord].push_back(i);
//             }
//         }
//         vector<int> result(n, -2);
//         vector<bool> visited(n,false);
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 int count = 0;
//                 for (int k = 0; k < len; k++)
//                 {
//                     if (wordList[i][k] != wordList[j][k])
//                     {
//                         count++;
//                     }
//                 }
//                 if (count == 1)
//                 {
//                     map[wordList[i]].push_back(j);
//                     map[wordList[j]].push_back(i);
//                 }
//             }
//         }
//         return 1 + minLength(map, beginWord, endWord, wordList, visited, result);
//     }
// };

class Solution
{
    void dfs(vector<vector<string>> &answer, vector<string> &path, int &smallestLength, string endWord, unordered_map<string, unordered_set<int>> &map, vector<string> &wordList, vector<bool> &visited)
    {
        int psize = path.size();
        string beginWord = path[psize - 1];
        if (beginWord == endWord)
        {
            if (psize == smallestLength)
            {
                answer.push_back(path);
            }
            else if (psize < smallestLength)
            {
                answer.clear();
                answer.push_back(path);
                smallestLength = psize;
            }
            return;
        }
        if (psize == smallestLength)
        {
            return;
        }
        for (auto i : map[beginWord])
        {
            if (!visited[i])
            {
                visited[i] = true;
                path.push_back(wordList[i]);
                dfs(answer, path, smallestLength, endWord, map, wordList, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, unordered_set<int>> map;
        int n = wordList.size();
        int len = beginWord.length();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int k = 0; k < len; k++)
            {
                if (wordList[i][k] != beginWord[k])
                {
                    count++;
                }
            }
            if (count == 1)
            {
                map[beginWord].insert(i);
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = 0;
                for (int k = 0; k < len; k++)
                {
                    if (wordList[i][k] != wordList[j][k])
                    {
                        count++;
                    }
                }
                if (count == 1)
                {
                    map[wordList[i]].insert(j);
                    map[wordList[j]].insert(i);
                }
            }
        }
        vector<vector<string>> answer;
        vector<bool> visited(n, false);
        vector<string> path;
        path.push_back(beginWord);
        int smallestLength = INT_MAX;
        dfs(answer, path, smallestLength, endWord, map, wordList, visited);
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob"};
    cout << sol.ladderLength("cet", "ism", words);
    return 0;
}