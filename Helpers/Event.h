#pragma once
#include <vector>
#include <functional>

class Event {
public:
    using Handler = std::function<void()>;

    void subscribe(Handler handler) {
        handlers.push_back(handler);
    }

    void invoke() {
        for (auto& h : handlers)
            h();
    }

private:
    std::vector<Handler> handlers;
};
