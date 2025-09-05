# Memory Allocation Strategies

## First Fit
First fit allocation finds the first available memory block that is large enough for the amount of memory the user wants to allocate. One of the cons of this approach is that there may be lots of fragmentation.

## Best Fit
Best fit allocation tries to minimize the amount of space wasted by finding the smallest suitable memory block. This technique tries to minimize the amount of space wasted, but could lead to many small fragments being unused due to memory blocks not being the perfect size for the amount of space the user wants allocated.
