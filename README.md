<style>
    table, tr, td {
        border: 1px solid;
    }
    td.param {font-family: monospace;}
    td.status {font-style: italic;}
</style>
# COOPS
## C Object-Oriented Programming Library
Coops introduces classes and code-as-data ideas into C using preprocessor macros.

### Macros
#### `class(name)`
This begins a classs named <code>name</code>.
```
...
class(Tester)
...
endClass(Tester)
...
```
<table>
    <tr>
        <td class=param>name</td>
        <td class=status>required</td>
        <td>The name of the class</td>
    </tr>
</table>

#### `endClass(name)`
This macro ends the class named `name`.<br/>
*[see example for `class`]*
<table>
    <tr>
        <td class=param>name</td>
        <td class=status>required</td>
        <td>The name of the class</td>
    </tr>
</table>

#### `expectMethod(retType, name, params)`
*Only valid inside a `class`*<br/>
Tells the class to make room for a method named `name` (since C is *not* dynamically typed)
```
class(Tester)
    ...
    expectMethod(void, test, ())
    ...
endClass(Tester)
```
<table>
    <tr>
        <td class=param>retType</td>
        <td class=status>required</td>
        <td>Return type of the method</td>
    </tr>
    <tr>
        <td class=param>name</td>
        <td class=status>required</td>
        <td>The name of the method</td>
    </tr>
    <tr>
        <td class=param>params</td>
        <td class=status>required</td>
        <td>Parameters of the method (in the form <code>(a,b,c)</code>)</td>
</table>

#### `method(cls, retType, name, params)`
*must be used inside a function such as `main`*<br/>
Begins the definition of method `name` on class `cls` with return type `retType` and parameters `params`.
```
method(Tester, void, test, ())
    ...
endMethod(Tester, test)
```
<table>
    <tr>
        <td class=param>cls</td>
        <td class=status>required</td>
        <td>The class that the method is part of</td>
    <tr>
        <td class=param>retType</td>
        <td class=status>required</td>
        <td>Return type of the method</td>
    </tr>
    <tr>
        <td class=param>name</td>
        <td class=status>required</td>
        <td>The name of the method</td>
    </tr>
    <tr>
        <td class=param>params</td>
        <td class=status>required</td>
        <td>Parameters of the method (in the form <code>(a,b,c)</code>)</td>
    </tr>
</table>

#### `endMethod(cls, name)`
*Must be used **after** a `method` and inside a function such as `main`*<br/>
Ends the method `cls.name`.<br/>
*[see example for `method`]*
<table>
    <tr>
        <td class=param>cls</td>
        <td class=status>required</td>
        <td>The class the method is part of</td>
    </tr>
    <tr>
        <td class=param>name</td>
        <td class=status>required</td>
        <td>The name of the method</td>
    </tr>
</table>

#### `init(cls)`
Calls the `__init__` method on the class `cls`, and returns the initialized instance.
```
...
classType(Tester) myTester = init(Tester);
...
```
<table>
    <tr>
        <td class=param>cls</td>
        <td class=status>required</td>
        <td>The name of the class</td>
    </tr>
</table>

#### `classType(cls)`
Returns the structure type of the class `cls`.<br/>
*[see example for `init`]*
<table>
    <tr>
        <td class=param>cls</td>
        <td class=status>required</td>
        <td>The class of which to get the structure type</td>
    </tr>
</table>
