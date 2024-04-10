List merge(List l1, List l2) {
    List merged_list = nullptr;
    List current = nullptr;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->info < l2->info) {
            if (merged_list == nullptr) {
                merged_list = new Cell{l1->info, nullptr};
                current = merged_list;
            } else {
                current->next = new Cell{l1->info, nullptr};
                current = current->next;
            }
            l1 = l1->next;
        } else {
            if (merged_list == nullptr) {
                merged_list = new Cell{l2->info, nullptr};
                current = merged_list;
            } else {
                current->next = new Cell{l2->info, nullptr};
                current = current->next;
            }
            l2 = l2->next;
        }
    }

    while (l1 != nullptr) {
        if (merged_list == nullptr) {
            merged_list = new Cell{l1->info, nullptr};
            current = merged_list;
        } else {
            current->next = new Cell{l1->info, nullptr};
            current = current->next;
        }
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        if (merged_list == nullptr) {
            merged_list = new Cell{l2->info, nullptr};
            current = merged_list;
        } else {
            current->next = new Cell{l2->info, nullptr};
            current = current->next;
        }
        l2 = l2->next;
    }

    return merged_list;
}
