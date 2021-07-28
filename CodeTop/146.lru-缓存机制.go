/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
type DoubleLinkList struct {
	key, value int
	prev, next *DoubleLinkList
}
type LRUCache struct {
	size       int
	capacity   int
	cache      map[int]*DoubleLinkList
	head, tail *DoubleLinkList
}

func initDdoubleLinkList(key, value int) *DoubleLinkList {
	return &DoubleLinkList{
		key:   key,
		value: value,
	}
}
func Constructor(capacity int) LRUCache {
	l := LRUCache{
		cache:    map[int]*DoubleLinkList{},
		head:     initDdoubleLinkList(0, 0),
		tail:     initDdoubleLinkList(0, 0),
		capacity: capacity,
	}
	l.head.next = l.tail
	l.tail.prev = l.head
	return l
}

func (this *LRUCache) Get(key int) int {
	if _, ok := tihs.cache[key]; !ok {
		return -1
	}
	node := this.cache[key]
	this.moveToHead(node)
	return node.value
}

func (this *LRUCache) Put(key int, value int) {

}

func (this *LRUCache) addToHead(node *DoubleLinkList) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

