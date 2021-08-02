/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
package codetopgo

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
	if _, ok := this.cache[key]; !ok {
		return -1
	}
	node := this.cache[key]
	this.moveToHead(node)
	return node.value
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; !ok {
		node := initDdoubleLinkList(key, value)
		this.cache[key] = node
		this.addToHead(node)
		this.size++
		if this.size > this.capacity {
			removed := this.removeTail()
			delete(this.cache, removed.key)
			this.size--
		}
	} else {
		node := this.cache[key]
		node.value = value
		this.moveToHead(node)
	}
}

func (this *LRUCache) addToHead(node *DoubleLinkList) {
	node.prev = this.head
	node.next = this.head.next
	this.head.next.prev = node
	this.head.next = node
}

func (this *LRUCache) removeHead(node *DoubleLinkList) {
	node.prev.next = node.next
	node.next.prev = node.prev
}

func (this *LRUCache) moveToHead(node *DoubleLinkList) {
	this.removeHead(node)
	this.addToHead(node)
}

func (this *LRUCache) removeTail() *DoubleLinkList {
	node := this.tail.prev
	this.removeHead(node)
	return node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
