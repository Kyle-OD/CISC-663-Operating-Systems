bool lock = false           // lock initialized to false

push(item) {
    while(lock = true) {
        //wait
    }
    lock = true             // lock shared variables
    if (top < SIZE) {
        stack[top] = item 
        top++ 
    }
    else
        ERROR
    lock = false            // unlock shared variables
}

pop() {
    while(lock = true) {
        //wait
    }
    lock = true             // lock shared variables
    if (!is_empty()) {
        top-- 
        result = stack[top] // temporary storage variable
        lock = false        // unlock shared variables
        return result 
    }
    else
        ERROR
        lock = false        // unlock shared variables
}

is_empty() {
    while(lock = true) {
        //wait
    }
    lock = true             // lock shared variables

    if (top == 0)
        lock = false        // unlock shared variables
        return true 
    else
        lock = false
        return false        // unlock shared variables
}

