#include<bits/stdc++.h>
void launch_minecraft(const std::string& version, const std::string& username) {
    // ��ȡ��Ҫ·��
    std::string java_path = ".\\jre\\bin\\java.exe";
    std::string mc_dir = ".\\.minecraft";
    std::string natives_dir = mc_dir + "\\versions\\" + version + "\\natives";
    std::string client_jar = mc_dir + "\\versions\\" + version + "\\" + version + ".jar";

    // ������������
    std::string command = 
        "\"" + java_path + "\"" +
        " -Xms2G -Xmx4G" +
        " -Djava.library.path=\"" + natives_dir + "\"" +
        " -cp \"" + mc_dir + "\\libraries\\*;" + client_jar + "\"" +
        " net.minecraft.client.main.Main" +
        " --version " + version +
        " --assetIndex " + version +
        " --assetsDir \"" + mc_dir + "\\assets\"" +
        " --gameDir \"" + mc_dir + "\"" +
        " --username " + username +
        " --accessToken 0" +
        " --userType legacy";

    std::cout << "\n�������� Minecraft " << version << " ...\n" << std::endl;
    std::system(command.c_str());
}

int main(int argc, char* argv[]) {
    std::string version, username;

    // ͨ�������в�����ȡ�汾���û���
    if (argc == 3) {
        version = argv[1];
        username = argv[2];
    } else {
        // �����в�������ʱ���ֶ�����
        std::cout << "Minecraft ������" << std::endl;
        std::cout << "������汾��: ";
        std::getline(std::cin, version);
        std::cout << "�������û���: ";
        std::getline(std::cin, username);
    }

    // ������Ϸ
    launch_minecraft(version, username);

    return 0;
}

