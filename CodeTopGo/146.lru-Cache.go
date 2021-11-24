/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
type DoubleListNode struct{
	key int
	val int
	next *DoubleListNode
	prev *DoubleListNode
}
type LRUCache struct {
	head *DoubleListNode
	tail *DoubleListNode
	memory map[int]*DoubleListNode
	cacheCapacity int
}

func initDoubleListNode(key int, value int)*DoubleListNode{
	return &DoubleListNode{
		key:key,
		val:value,
	}
}


func Constructor(capacity int) LRUCache {
	lru := LRUCache{
		cacheCapacity : capacity,
		head : initDoubleListNode(0,0),
		tail : initDoubleListNode(0,0),
		memory : map[int]*DoubleListNode{},
	}
	lru.head.next = lru.tail
	lru.tail.prev = lru.head
	return lru
}


func (this *LRUCache) Get(key int) int {
	if v,ok := this.memory[key]; ok{
		this.updateStatus(key)
		return v.val
	}
	return -1
}


func (this *LRUCache) Put(key int, value int)  {
	if v,ok := this.memory[key]; ok{
		v.val = value
		this.updateStatus(key)
		return
	}
	if len(this.memory) == this.cacheCapacity{
		topKey := this.head.next.key
		this.removeNode(this.head.next)
		delete(this.memory,topKey)
	}
	newNode := initDoubleListNode(key,value)
	this.memory[key] = newNode
	this.pushNode(newNode)
}

func (this *LRUCache) updateStatus(key int){
	node := this.memory[key]
	this.removeNode(node)
	this.pushNode(node)
}

func (this *LRUCache) removeNode(node *DoubleListNode){
	node.next.prev = node.prev
	node.prev.next = node.next
	node.prev = nil
	node.next = nil
}

func (this *LRUCache) pushNode(node *DoubleListNode){
	this.tail.prev.next = node
	node.prev = this.tail.prev
	node.next = this.tail
	this.tail.prev = node
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

