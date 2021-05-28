investigation:
  travel_variant: "Direction"
  experiments:
  - experiment: 
      number: 1
      input_data:
        buffer_size: "128 kb"
      results:
        duration: "3.6 ns"
  - experiment:
      number: 2
      input_data:
        buffer_size: "2 mb"
      results:
        duration: "3.8 ns"
  - experiment: 
      number: 3
      input_data:
        buffer_size: "4 mb"
      results:
        duration: "5.2 ns"
  - experiment: 
      number: 4
      input_data:
        buffer_size: "8 mb"
      results:
        duration: "5.6 ns"
  - experiment: 
      number: 5
      input_data:
        buffer_size: "9 mb"
      results:
        duration: "6.5 ns"

investigation:
  travel_variant: "Backward"
  experiments:
  - experiment:
      number: 1
      input_data:
        buffer_size: "128 kb"
      results:
        duration: "3.3 ns"
  - experiment:
      number: 2
      input_data:
        buffer_size: "2 mb"
      results:
        duration: "4.3 ns"
  - experiment:
      number: 3
      input_data:
        buffer_size: "4 mb"
      results:
        duration: "5.4 ns"
  - experiment:
      number: 4
      input_data:
        buffer_size: "8 mb"
      results:
        duration: "6.3 ns"
  - experiment:
      number: 5
      input_data:
        buffer_size: "9 mb"
      results:
        duration: "6.9 ns"

investigation:
  travel_variant: "Random"
  experiments:
  - experiment:
      number: 1
      input_data:
        buffer_size: "128 kb"
      results:
        duration: "97.4 ns"
  - experiment:
      number: 2
      input_data:
        buffer_size: "2 mb"
      results:
        duration: "125.6 ns"
  - experiment:
      number: 3
      input_data:
        buffer_size: "4 mb"
      results:
        duration: "139.6 ns"
  - experiment:
      number: 4
      input_data:
        buffer_size: "8 mb"
      results:
        duration: "150.7 ns"
  - experiment:
      number: 5
      input_data:
        buffer_size: "9 mb"
      results:
        duration: "190.2 ns"
