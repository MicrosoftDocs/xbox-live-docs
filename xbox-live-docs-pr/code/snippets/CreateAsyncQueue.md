```cpp
    async_queue_handle_t queue = nullptr;
    HRESULT hr = CreateAsyncQueue(
        AsyncQueueDispatchMode_Manual,
        AsyncQueueDispatchMode_Manual,
        &queue);
```
