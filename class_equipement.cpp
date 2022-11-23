while (getline(stock,tempStock)) {
		//separer le nom de l'agent de ses localisations
		vector<string> stockAttributes;
		boost::split(stockAttributes, tempStock, boost::is_any_of("\t"));
		//separer chaque loc
		vector<string> locInstances;
		boost::split(locInstances, stockAttributes[2], boost::is_any_of(";"));
		
		vector<Localisations*> trueLocInstances;
		//pour chaque loc
		for (auto instance : locInstances) {
			//separer le nom de la quantité
			vector<string> tempLocInstance;
			boost::split(tempLocInstance, instance, boost::is_any_of(","));
			//instancier la loc depuis son template et l'append au vector de loc de l'agent
			for (auto template : locAvailable) {
				if (template->getName() == tempLocInstance[1]){ // cherche un match de nom
					trueLocInstances.pushback()
				}
			}
		}
}