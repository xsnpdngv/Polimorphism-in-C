# A possible way to achieve polymorphism in C

## Introduction

Polymorphism is key to Object Orientation. It means that seemingly the
same thing can behave differently, depending on the actual underlying
type.

```
obj.func()
objP->func()
```

The behavior of `func` depends on the type of `obj`, therefore `func` is
polymorphic.

Saying "Polymorphism can be achieved by using switch statements
or long if/else chains within a function." would be true without
the following constraint:

"The mechanism of polymorphism must not create a source code dependency
from the caller to the callee."


## Goal

Make possible to

- Extend _Data Structure_
- Alter and extend _Behaviour_
