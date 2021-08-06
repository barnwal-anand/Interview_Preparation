>> Inter-process communication (IPC) is a mechanism that allows processes to communicate with each other
and synchronize their actions.
 1. Shared Memory
 2. Message Passing

Shared Memory Method:
---------------------
Producer-Consumer problem:
The producer produces some items and the Consumer consumes that item.
The two processes share a common space or memory location known as a buffer
where the item produced by the Producer is stored and from which the Consumer consumes the item if needed.

First, the Producer and the Consumer will share some common memory, then the producer will start producing items.
If the total produced item is equal to the size of the buffer, the producer will wait to get it consumed by the Consumer.
Similarly, the consumer will first check for the availability of the item.
If no item is available, the Consumer will wait for the Producer to produce it.
If there are items available, Consumer will consume them.
The pseudo-code to demonstrate is provided below:
free_index = 0;
full_index = 0;
Producer:
while(1)
{
      // check if there is no space for production. if so keep waiting.
      while((free_index + 1) % buff_max == full_index);
      shared_buff[free_index] = itemProduced;
      free_index = (free_index + 1) mod buff_max;
}
Consumer:
while(1){
	// check if there is an available item for consumption.
	// if not keep on waiting for get them produced.
	while((free_index == full_index);
	nextConsumed = shared_buff[full_index];
	full_index = (full_index + 1) mod buff_max;
}
