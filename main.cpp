#include <iostream>
#include <vector>
#include <string>


class Candidate {
	public:
		std::string name = "";
		int votes, seats;
		float porcent = 0.f;
		std::vector<float> dividedVotes;

		Candidate(std::string name, int votes, float porcent, int seats, std::vector<float> dividedVotes) {
		this->name = name;
		this->votes = votes;
		this->porcent = porcent;
		this->seats = seats;
		this->dividedVotes = dividedVotes;
		}

		~Candidate() {
			//
		}
	
	private:
		//
};



float calculatePorcent(int totalVotes, int candidateVotes, int whiteVotes, int nullVotes) {
	float porcent = (candidateVotes/(totalVotes - whiteVotes - nullVotes)) * 100;
	return porcent;
}


void calculateSeats(int seats, float minimumPorcent, std::vector<Candidate> candidates) {
	std::vector<float> biggestNumbers;

	for(int i = 0; i < seats; ++i) {
		for (Candidate candidate : candidates) {
			for (float number : biggestNumbers) {
				for (float dividedVote : candidate.dividedVotes) {
					if (dividedVote > number) biggestNumbers[i] = dividedVote;
				}
			}
		}
	}
}


std::vector<float> divideVotes(int votes, int seats) {
	std::vector<float> votesDivided;
	
	for(int i = 0; i < seats; ++i) {
		votesDivided[i] = votes/(i+1);
	}
	return votesDivided;
}



int main() {
	
	std::string line = "";
	int numberCandidates, totalVotes, whiteVotes, nullVotes, seats;
	float minimumPorcent;


	std::cout << "Total Votes ";
	std::cin >> line;
	totalVotes = std::stoi(line);

	std::cout << "White Votes: ";
	std::cin >> line;
	whiteVotes = std::stoi(line);

	std::cout << "Null Votes: ";
	std::cin >> line;
	nullVotes = std::stoi(line);

	std::cout << "Number of Seats: ";
	std::cin >> line;
	seats = std::stoi(line);

	std::cout << "Minimum Porcent of the votes to be able to get seats: ";
	std::cin >> line;
	minimumPorcent = std::stof(line);


	std::cout << "Number of Candidates: ";
	std::cin >> line;
	numberCandidates = std::stoi(line);

	std::vector<Candidate> candidates;

	for (int i = 0; i < numberCandidates; ++i) {
		std::string name;
		int votes;

		std::cout << "Name: ";
		std::cin >> name;

		std::cout << "Votes: ";
		std::cin >> line;
		votes = std::stoi(line);


		float porcent = calculatePorcent(totalVotes, votes, whiteVotes, nullVotes);
		std::vector<float> dividedVotes = divideVotes(votes, seats);
		Candidate candidate(name, votes, porcent, 0, dividedVotes);
		candidates[i] = candidate;
	}

	calculateSeats(seats, minimumPorcent, candidates);

	for (int i = 0; i < candidates.size(); ++i) {
		Candidate currentCandidate = candidates[i];
		std::cout << "The Candidate " << currentCandidate.name << " with " << currentCandidate.votes << " votes and the " << currentCandidate.porcent << "'%' of the votes and " << currentCandidate.seats << " of the " << seats << " seats" << std::endl;
	}
	
	return 0;
}
