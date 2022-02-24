# :heavy_check_mark: philoshopers
This project is aim to understand multi-threads programming with the use of mutex and this project is a part methodology learning students from 42 school (21 school in Moscow). 
Problem description:
# Problem description
Consider n philosophers who spend their lives thinking and eating. The philosophers share a circular table surrounded by five chairs, 
each belonging to one philosopher. In the center of the table is a bowl of rice, and the table is laid with five single chopsticks. 
When a philosopher thinks, he does not interact with her colleagues. 
From time to time, a philosopher gets hungry and tries to pick up the two chopsticks that are closest to him (the chopsticksthat are between 
his and her left and right neighbors). 
A philosopher may pick up only one chopstick at a time. Obviously, he cannot pick up a chopstick that is already in the hand of a neighbor. 
When a hungry philosopher has both her chopsticks at the same time, he eats without releasing the chopsticks. When he is finished eating, 
he puts down both chopsticks and starts thinking again.
## Usage
Use ``make`` to build the binary and then to run the simulation use ``./philo`` with specified arguments

**Secified arguments:** *number_of_philosophers*, *time_to_die*, *time_to_eat*, *time_to_sleep*, *[number_of_times_each_philosopher_must_eat]*

◦ number_of_philosophers: The number of philosophers and also the number
of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal 
or the beginning of the simulation, they die.

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least 
*number_of_times_each_philosopher_must_eat times*, the simulation stops. If not specified, the simulation stops when a philosopher dies.


## Other
**Author:**  
:vampire:*[Deeds Baron](https://github.com/DeedsBaron)*  
