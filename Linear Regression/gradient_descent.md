
## Gradient Descent Function

$$ W_{t+1} = W_t - (lr)*\frac{dC}{dw}$$
where lr is the learning rate of the model and next to it is the derivative of the cost
## Solving for Gradient Descent

We formulate the loss/cost function as MSE:
$$ loss = \frac{1}{N}\sum_{i=1}^n(y_i - \hat y_i )^2 $$

so we need to calculate the gradient (derivative) of the loss function as

$$ \frac{dloss}{dw} $$

we can define a few different functions as parameters:

$$ loss(y, w, x) = \frac{1}{N}\sum_{i=1}^n(y_i - \hat y_i )^2 \\ u(w, x) = \hat y_i \\ v(y, u) = y - u\\ loss(v) = \frac{1}{N}\sum_{i=1}^n(v)^2  $$

Since we didnt define some kind of bias, we have our ypred be:

$$ \hat y_i = x_i * w $$

$$ loss(y, w, x) = \frac{1}{N}\sum_{i=1}^n(y_i - (x_i * w) )^2 \\ u(w, x) = \hat y_i \\ v(y, u) = y - u\\ loss(v) = \frac{1}{N}\sum_{i=1}^n(v)^2  $$

let l = loss(v)

$$ \frac{dl}{dw} = \frac{d}{dw}(\frac{1}{N}\sum_{i=1}^n(v)^2) $$
$$ \frac{dl}{dw} = \frac{1}{N}\sum_{i=1}^n2(v) $$
$$ \frac{dl}{dw} = \frac{2}{N}\sum_{i=1}^nv $$
$$ \frac{dl}{dw} = \frac{2}{N}\sum_{i=1}^n(y-u) $$
$$ \frac{dl}{dw} = \frac{2}{N}\sum_{i=1}^n(-(y_i - u)* x_i) $$
$$ \frac{dl}{dw} = -\frac{2}{N}\sum_{i=1}^nx_i(y_i-\hat y_i) $$
let error or $e_i$ = $(y_i-\hat y_i)$
$$ \frac{dl}{dw} = -\frac{2}{N}\sum_{i=1}^nx_i * e_i $$
