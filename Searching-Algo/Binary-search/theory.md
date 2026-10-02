# Summary of Trade-offs

* Linear Search: Zero overhead, works on any unsorted sequence, best for tiny inputs.

* Binary Search: Optimal when data is already sorted, space-efficient, supports range and order queries.

* Hashing: Fastest average-case lookup ($\mathcal{O}(1)$), ideal for exact match lookups (dictionaries, databases, caches), but uses more memory and loses ordering.
