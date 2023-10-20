
class CountIntervals {
    var arr = [(Int, Int)]()
    var cnt = 0
    init() {

    }
    
    func add(_ left: Int, _ right: Int) {
        // 找 left 左侧有交集的区间
        var lo = 0, hi = arr.count - 1
        while lo <= hi {
            let mid = (lo + hi) / 2
            if arr[mid].1 < left {
                lo = mid + 1
            } else {
                hi = mid - 1
            }
        }
        // hi < left, 有交集的是 lo，但可能越界
        if lo == arr.count {
            arr.append((left, right))
            cnt += right - left + 1
            return
        }
        if arr[lo].0 > right {
            arr.insert((left, right), at: lo)
            cnt += right - left + 1
            return
        }
        let end = lo
        // 找 right 右侧有交集的区间
        lo = 0; hi = arr.count - 1
        while lo <= hi {
            let mid = (lo + hi) / 2
            if arr[mid].0 > right {
                hi = mid - 1
            } else {
                lo = mid + 1
            }
        }
        // lo > right, 有交集的是 hi，但可能越界
        if hi == -1 {
            arr.insert((left, right), at: 0)
            cnt += right - left + 1
            return
        }
        if arr[hi].1 < left {
            arr.insert((left, right), at: hi)
            cnt += right - left + 1
            return
        }
        let start = hi
        print(left, right, arr, cnt, start, end)
        let mx = max(right, arr[end].1)
        let mn = min(left, arr[start].0)
        cnt += right - left + 1
        for i in stride(from: end, through: start, by: -1) {
            let cur = arr[i]
            cnt -= min(cur.1, right) - max(cur.0, left) + 1
            if i != start {
                arr.remove(at: i)
            } else {
                arr[i].1 = mx
                arr[i].0 = mn
            }
        }
    }
    
    func count() -> Int {
        return cnt
    }
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * let obj = CountIntervals()
 * obj.add(left, right)
 * let ret_2: Int = obj.count()
 */

let ops = ["CountIntervals","count","add","add","count","add","count","count","add","count","count","add","add","count","add","add","add","count","add","count","count","add","count","add","count","add","add","add","count","add","add","add","count","add","add","add","count","count","count","count","count","count","add","add","add","count","count","add","count","count","add","add","count","count","count","add","count","count","add","add","add","count","count","add","count","count","add","add","count","count","add","add","count","count","add","add","add","add","add","add","add","add","count","count","add","count","count","add","add","add","add","count","count","add","count","count","count","count","add","count","count","add","count","add","count","add","count","add","count","add","add","add","add","add","add","count","count","count","add"]
let params = [[],[],[457,717],[918,927],[],[660,675],[],[],[885,905],[],[],[323,416],[774,808],[],[671,787],[133,963],[374,823],[],[494,556],[],[],[564,898],[],[514,530],[],[702,950],[282,695],[324,943],[],[893,975],[337,869],[674,981],[],[847,966],[12,544],[706,862],[],[],[],[],[],[],[633,964],[17,86],[209,315],[],[],[974,995],[],[],[106,817],[873,886],[],[],[],[255,422],[],[],[71,927],[852,889],[980,994],[],[],[477,649],[],[],[76,426],[508,510],[],[],[345,611],[816,980],[],[],[848,924],[855,914],[621,740],[176,801],[258,451],[229,540],[119,482],[801,917],[],[],[308,877],[],[],[927,961],[546,881],[563,867],[64,284],[],[],[289,540],[],[],[],[],[851,898],[],[],[330,400],[],[724,826],[],[316,578],[],[95,973],[],[469,971],[568,806],[775,953],[556,958],[109,488],[142,305],[],[],[],[686,778]]
let n = ops.count
let obj = CountIntervals()
for i in 0..<n {
    if ops[i] == "count" {
        print(obj.count())
    } else if (ops[i] == "add") {
        obj.add(params[i][0], params[i][1])
    }
}
