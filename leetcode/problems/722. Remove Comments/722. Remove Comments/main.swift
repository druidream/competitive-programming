// WA屎山
//class Solution {
//    func removeComments(_ source: [String]) -> [String] {
//        var res = [String]()
//        var flag = false
//        outer:
//        for line in source {
//            if !flag { res.append("") }
//            let s = Array(line), m = s.count
//            var i = 1
//            var start = 0
//            while i < m {
//                if !flag && s[i - 1] == "/" && s[i] == "/" {
//                    if start < i {
//                        let t = String(s[start..<i - 1])
//                        res[res.count - 1] += t
//                    }
//                    start = m
//                    break
//                }
//                if flag && s[i - 1] == "*" && s[i] == "/" {
//                    flag = !flag
//                    start = i + 1
//                    i += 1
//                }
//                if i < m && !flag && s[i - 1] == "/" && s[i] == "*" {
//                    res[res.count - 1] += String(s[0..<i - 1])
//                    flag = !flag
//                    i += 1
//                }
//                i += 1
//            }
//            if !flag && start < m {
//                res[res.count - 1] += String(s[start...])
//            }
//            if res[res.count - 1] == "" { res.removeLast() }
////            print(res)
//        }
//        return res
//    }
//}

class Solution {
    func removeComments(_ source: [String]) -> [String] {
        // var res = [String]()
        // var newLine = ""
        // var inBlock = false
        // for line in source {
        //     let s = Array(line), m = s.count
        //     var i = 0
        //     while i < m {
        //         if inBlock {
        //             if i + 1 < m && s[i] == "*" && s[i + 1] == "/" {
        //                 inBlock = false
        //                 i += 1
        //             }
        //         } else {
        //             if i + 1 < m && s[i] == "/" && s[i + 1] == "*" {
        //                 inBlock = true
        //                 i += 1
        //             } else if i + 1 < m && s[i] == "/" && s[i] == "/" && s[i + 1] == "/" {
        //                 break
        //             } else {
        //                 newLine.append(s[i])
        //             }
        //         }
        //         i += 1
        //     }

        //     if !inBlock && newLine != "" {
        //         res.append(newLine)
        //         newLine = ""
        //     }
        // }
        // return res
        var res = [String]()
        var flag = false
        outer:
        for line in source {
//            if !flag { res.append("") }
            let s = Array(line), m = s.count
            var i = 0
            // 从单个字符的视角考虑，不要从区间的视角考虑
            // var start = 0
            var t = ""
            while i < m {
                if i == m - 1 {
                    if flag {
                        t.append(s[i])
                    }
                    break
                }
                if !flag && s[i] == "/" && s[i + 1] == "/" {
                    // if start < i {
                    //     let t = String(s[start..<i - 1])
                    //     res[res.count - 1] += t
                    // }
                    // start =
                    break
                }
                if flag && s[i] == "*" && s[i + 1] == "/" {
                    flag = !flag
                    // start = i + 1
                    i += 1 // 跳过后一个字符，不能有重叠字符：/*/
                } else if !flag && s[i] == "/" && s[i + 1] == "*" {
                    // res[res.count - 1] += String(s[0..<i - 1])
                    flag = !flag
                    i += 1
                } else if !flag {
                    t.append(s[i])
                }
                i += 1
            }
            if !flag && t != "" {
                res.append(t)
            }
            // if !flag && start < m {
            //     res[res.count - 1] += String(s[start...])
            // }
            // if res[res.count - 1] == "" { res.removeLast() }
            // print(res)
        }
        return res
    }
}
//print(Solution().removeComments(["a//*b//*c","blank","d/*/e*//f"]))
print(Solution().removeComments(["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]))
