        
        #'''
        epsilon = 0.01
        # stage 1: accumulate information about the transitions
        for episode in corpus:
            hidden_states = episode.getKnownState()
            transitions = self.transitions

            # deal with the initial distribution tallying here
            intial_hidden_state = hidden_states[0]
            if intial_hidden_state in transitions['#']:
                transitions['#'][intial_hidden_state] += 1
            else:
                transitions['#'][intial_hidden_state] = 1

            # Iterate through emissions in the episode and tally the transitions between states
            for i, j in zip(hidden_states, hidden_states[1:]):
                # hidden_state_i transitions to hidden_state_j
                if i in transitions:  # check if we have seen the hidden state before
                    if j in transitions[i]:  # check if i has transitioned to j before
                        transitions[i][j] += 1  # increment the count
                    else:  # initialize an entry for j
                        transitions[i][j] = 1
                else:  # initialize a dictionary for transitions from i
                    transitions[i] = {j: 1}

        # stage 2: process accumulated transition information into Laplace smoothed probabilities
        for i in transitions:
            denominator = sum(transitions[i].values()) + ((len(transitions[i])) * epsilon)
            for j in transitions[i]:
                numerator = transitions[i][j] + epsilon
                self.transitions[i] = {j: numerator / denominator}

        ''' Learn emissions '''
        # stage 1: accumulate information about the emissions
        emissions = self.emissions  # state -> emission -> number of times transitioned

        for episode in corpus:
            hidden_states = episode.getKnownState()
            observations = episode.asList()
            for hs, obs in zip(hidden_states, observations):
                if obs in emissions[hs]:
                    emissions[hs][obs] += 1
                # else:
                #     emissions[hs]['UNKNOWN'] += 1
        for key in emissions:
            emissions[key]['UNKNOWN'] = 0

        # step 2: process accumulated information into Laplace smoothed emission probabilities
        for hs in emissions:
            Ei = len(emissions[hs])
            denominator = sum(emissions[hs].values()) + (Ei * epsilon)
            for obs in emissions[hs]:
                numerator = emissions[hs][obs] + epsilon
                self.emissions[hs][obs] = numerator / denominator
        #'''
